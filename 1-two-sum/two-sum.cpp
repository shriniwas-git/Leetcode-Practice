class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                i = nums[i];
                j=nums[j];
                break;
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                i++;
            }
        }
        int i1=0,i2=0;
        for(int k=0;k<temp.size();k++){
            if(temp[k]==i && i1==0){
                i1=k;
            }else if(temp[k]==j){
                i2=k;
            }
        }
        return {i1,i2};
    }
};