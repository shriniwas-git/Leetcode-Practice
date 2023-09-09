class Solution {
public:
    int func(int target,vector<int>& nums,vector<int> &dp){
        
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int take=0;
        for(int j=0;j<nums.size();j++){
            take+=func(target-nums[j],nums,dp);
        }
        // int ntake = func(target-nums[ind],nums,ind+1);
        return dp[target] = take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        func(target,nums,dp);
        return dp[target];
    }
};