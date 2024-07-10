class Solution {
public:
    int subarraysAtmostK(vector<int> &nums,int k){
        if(k<0){
            return 0;
        }
        int ct = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        map<int,int> mpp;
        while(right<n){
            mpp[nums[right]]++;
            while(left<n && mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            if(mpp.size()<=k){
                ct+=(right-left+1);
            }
            right++;
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysAtmostK(nums,k) - subarraysAtmostK(nums,k-1);
    }
};