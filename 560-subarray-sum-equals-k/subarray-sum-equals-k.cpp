class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end()){
                ans +=mpp[rem];
            }
            mpp[sum]++;
            
        }
        return ans;
    }
};