class Solution {
public:
    int func(long long mid,vector<int> &nums,int k){
        int ct=1;
        int tsum = 0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            if(tsum>mid){
                ct++;
                tsum = nums[i];
            }
        }
        if(ct>k){
            return 1;
        }
        return 0;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        long long sum = 0;
        int ans = -1;
        for(auto it: nums){
            sum+=it;
        }
        long long high = sum;
        while(low<=high){
            long long mid = (low+high)/2;
            int val = func(mid,nums,k);
            if(val==1){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};