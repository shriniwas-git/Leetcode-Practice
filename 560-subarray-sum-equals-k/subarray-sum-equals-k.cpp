class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        int sum = 0;
        int ct = 0;
        mpp[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum - k;
            ct+=mpp[rem];
            mpp[sum]++;
        }
        return ct;
    }
};