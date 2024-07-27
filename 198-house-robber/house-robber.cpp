class Solution {
public:
    int robHelper(vector<int> &nums,int ind,vector<int> &dp){
        int n = nums.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int robHere = nums[ind] + robHelper(nums,ind+2,dp);
        int doesntRob = robHelper(nums,ind+1,dp);
        return dp[ind] = max(robHere,doesntRob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return robHelper(nums,0,dp);
    }
};