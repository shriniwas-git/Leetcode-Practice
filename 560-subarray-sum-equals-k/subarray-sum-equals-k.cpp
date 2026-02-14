class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ct = 0;
        map<int,int> mpp; //presum, count
        int presum = 0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int rem  = presum-k;
            if(mpp.find(rem)!=mpp.end()){
                ct+=mpp[rem];
            }
            mpp[presum]++;
        }
        return ct;
    }
};