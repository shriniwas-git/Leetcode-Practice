class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = nums[0],sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum+nums[i]<nums[i]){
                sum = nums[i];
            }else{
                sum+=nums[i];
            }
            msum = max(sum,msum);
        }
        return msum;
    }
};