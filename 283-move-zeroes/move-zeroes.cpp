class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j = i;
                break;
            }
        }
        if(j==-1){
            return;
        }
        i = j+1;
        while(i<nums.size()){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            
            i++;
        }
    }
};