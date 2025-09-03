class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        int st = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ct++;
            }else{
                nums[st++] = nums[i];
            }
        }
        int j = n-1;
        while(ct--){
            nums[j--] = 0;
        }
        
    }
};