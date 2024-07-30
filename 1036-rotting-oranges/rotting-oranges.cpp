class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rot = grid;
        queue<pair<int,pair<int,int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rot[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curTime = it.first;
            time = max(time,it.first);
            int row = it.second.first;
            int col = it.second.second;
            for(int i=0;i<=3;i++){
                int nrow = dr[i] + row;
                int ncol = dc[i] + col;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && rot[nrow][ncol]==1){
                    rot[nrow][ncol] = 2;
                    q.push({curTime+1,{nrow,ncol}});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rot[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};