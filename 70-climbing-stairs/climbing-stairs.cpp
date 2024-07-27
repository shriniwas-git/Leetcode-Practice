class Solution {
public:
    int func(int ind,vector<int> &dp){
        if(ind<=0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int oneStep = func(ind-1,dp);
        int twoSteps = 0;
        if(ind>=2){
            twoSteps = func(ind-2,dp);
        }
        return dp[ind] = oneStep + twoSteps;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};