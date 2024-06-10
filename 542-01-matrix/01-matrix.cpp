class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> dis(n, vector<int> (m,1e9));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first.first;
            int c = cur.first.second;
            int dist = cur.second;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                    dis[nr][nc] = dist+1;
                }
            }
        }
        return dis;
    }
};