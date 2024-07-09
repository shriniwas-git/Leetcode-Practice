class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = 0;
        int ct0 = 0;
        while(right<n){
            if(nums[right]==1){
                ans = max(ans,right-left+1);
                right++;
            }else{
                if(ct0<k){
                    ct0++;
                    ans = max(ans,right-left+1);
                    right++;
                }else{
                    while(left<n && ct0>=k){
                        if(nums[left]==0){
                            ct0--;
                        }
                        left++;
                    }
                    ct0++;
                    ans = max(ans,right-left+1);
                    right++;

                }
            }
        }
        return ans;
    }
};