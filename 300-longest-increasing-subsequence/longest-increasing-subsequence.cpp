class Solution {
public:
    int func(int ind,int prev_ind,vector<int> nums,vector<vector<int>> &dp){
        
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        int take = 0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take = 1 + func(ind+1,ind,nums,dp);
        }
        int nottake = func(ind+1,prev_ind,nums,dp);
        return dp[ind][prev_ind+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        vector<int> next(n+1,0), cur(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                int take = 0;
            if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                take = 1 + next[ind+1];
            }
            int nottake = next[prev_ind+1];
            cur[prev_ind+1] = max(take,nottake);
            }
            next  = cur;
        }
        int ans = next[0];
        return ans;
    }
};