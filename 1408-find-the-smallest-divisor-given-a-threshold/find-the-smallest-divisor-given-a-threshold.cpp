class Solution {
public:
    int func(long long mid,vector<int> &nums,int threshold){
        int ct=0;
        for(int i=0;i<nums.size();i++){
            int val = nums[i]/mid;
            if(nums[i]%mid!=0){
                val+=1;
            }
            ct+=val;
        }
        if(ct<=threshold){
            return 1;
        }
        return 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long low = 1;
        long long high = *max_element(nums.begin(),nums.end());
        long long ans = 1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = func(mid,nums,threshold);
            if(val==1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};