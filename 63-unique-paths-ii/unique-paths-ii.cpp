class Solution {
public:
    int func(int r,int c,vector<vector<int>>& og,vector<vector<int>> &dp){
        if(r<0 || c<0){
            return 0;
        }
        
        if(og[r][c]==1){
            return 0;
        }
        if(r==0 && c==0){
            return 1;
        }
        
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int up = func(r-1,c,og,dp);
        int left = func(r,c-1,og,dp);
        return dp[r][c] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        int ans = func(n-1,m-1,obstacleGrid,dp);
        return ans;
    }
};