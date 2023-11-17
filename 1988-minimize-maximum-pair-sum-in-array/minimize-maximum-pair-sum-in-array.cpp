class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = nums[0] + nums[nums.size()-1];
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            sum = max(sum,nums[i]+nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};