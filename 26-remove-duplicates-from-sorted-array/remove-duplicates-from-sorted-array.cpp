class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0;
        int n = nums.size();
        while(i<n){
            if(nums[i]!=nums[j]){
                nums[j+1] = nums[i];
                j++;
                i++;
            }else{
                i++;
            }
        }
        return j+1;
    }
};