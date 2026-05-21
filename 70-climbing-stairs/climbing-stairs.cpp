class Solution {
public:
    int func(int ind,vector<int> &dp){
        if(dp[ind]!=-1){
            return dp[ind];
        }
        if(ind==1 || ind==0){
            return 1;
        }
        int one = func(ind-1,dp);
        int two  = func(ind-2,dp);
        return dp[ind] = one+two; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = func(n,dp);
        return ans;
    }
};