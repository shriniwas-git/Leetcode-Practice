class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }else if(n==2){
            return min(nums[0],nums[1]);
        }else{
            for(int i=0;i<n-1;i++){
                if(nums[i+1]<nums[i]){
                    return nums[i+1];
                }
                
            }
            
        }
        return nums[0];
    }
};