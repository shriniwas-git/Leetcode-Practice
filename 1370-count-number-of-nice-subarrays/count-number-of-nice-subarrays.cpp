class Solution {
public:
    int atMostkOdd(vector<int> &nums,int k){
        if(k<0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ct= 0;
        int ans = 0;
        while(right<n){
            if(nums[right]%2){
                ct++;
            }
            while(left<n && ct>k){
                if(nums[left]%2){
                    ct--;
                }
                left++;
            }
            if(ct<=k){
                ans +=(right-left+1);
            }
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostkOdd(nums,k) - atMostkOdd(nums,k-1);
    }
};