class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        if(nums.size()==2){
            if(nums[0]>=1){
                return true;
            }
            return false;
        }
        int rq = 1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=rq){
                rq=1;
            }else{
                rq++;
            }
        }
        if(rq==1){
            return true;
        }
        return false;
    }
};