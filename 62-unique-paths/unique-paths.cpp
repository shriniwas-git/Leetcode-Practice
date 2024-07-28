class Solution {
public:
    int func(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==0 && j==0){
            return 1;
        }
        int left = func(i-1,j,dp);
        int up = func(i,j-1,dp);
        return dp[i][j] = (left + up);

    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        // return func(m-1,n-1,dp);
        // dp[0][0] = 1;
        int lvar =0,upvar = 0;
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n+1,0);
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) {
                temp[j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
                }
                int left = 0;
                if(i>=1){
                    left = dp[j];
                }
                int up = 0;
                if(j>0){
                    up = temp[j-1];
                }
                temp[j] = (left + up);
            }
            dp = temp;
        }
        return dp[n-1];
    }
};