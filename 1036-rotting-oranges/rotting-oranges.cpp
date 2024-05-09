class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    cout << i << j << endl;
                }
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        int ans = 0;
        while(!q.empty()){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int val = q.front().first;
            q.pop();
            ans = max(ans,val);
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({val+1,{nx,ny}});
                }
            }
        }
        // int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans = -1;
                    // ct++;
                }
            }
        }
        return ans;
    }
};