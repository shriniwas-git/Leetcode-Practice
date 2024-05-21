class Solution {
public:
    int func(int i,int n,vector<int> &dp){
        if(i>n){
            return 0;
        }
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int p1 = func(i+1,n,dp);
        int p2 = func(i+2,n,dp);
        return dp[i] = (p1+p2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = func(0,n,dp);
        return ans;
    }
};