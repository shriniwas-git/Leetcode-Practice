class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m,vector<int> (n,1e9));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curDist = it.first;
            int curRow = it.second.first;
            int curCol = it.second.second;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i=0;i<=3;i++){
                int nRow = curRow + dr[i];
                int nCol = curCol + dc[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && dist[nRow][nCol]==1e9){
                    dist[nRow][nCol] = curDist + 1;
                    q.push({curDist+1,{nRow,nCol}});
                }
            }
            
        }
        return dist;
    }
};