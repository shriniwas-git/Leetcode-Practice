class Solution {
public:
    int sumatMostGoal(vector<int> &nums,int goal){
        if(goal<0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = 0;
        int ct = 0;
        while(right<n){
            if(nums[right]==1){
                ct++;
            }
            while(left<n && ct>goal){
                if(nums[left]==1){
                    ct--;
                }
                left++;
            }
            if(ct<=goal){
                ans += (right-left+1);
            }
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumatMostGoal(nums,goal) - sumatMostGoal(nums,goal-1);
    }
};