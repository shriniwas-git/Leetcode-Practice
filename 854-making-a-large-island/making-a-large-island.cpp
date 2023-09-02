class DisjointSet {
    
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                    int nr = i + dr[ind];
                    int nc = j + dc[ind];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nodeno = i*n + j;
                        int adjno = nr*n + nc;
                        ds.unionBySize(nodeno,adjno);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int> comp;
                for(int ind=0;ind<4;ind++){
                    int nr = i + dr[ind];
                    int nc = j + dc[ind];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        comp.insert(ds.findUPar(nr*n + nc));
                    }
                }
                int szt = 0;
                for(auto it :comp){
                    szt+=ds.size[it];
                }
                mx = max(mx,szt+1);

            }
        }
        for(int i=0;i<n*n;i++){
            mx = max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};