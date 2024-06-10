class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first.first;
            int c = cur.first.second;
            int curTime = cur.second;
            time = max(time,curTime);
            for(int i=0;i<4;i++){
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m 
                && vis[newRow][newCol]==0 && grid[newRow][newCol]==1){
                    vis[newRow][newCol] = 1;
                    grid[newRow][newCol] = 2;
                    q.push({{newRow,newCol},curTime+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};