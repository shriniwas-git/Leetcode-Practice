class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ct0=0,ct1=0,ct2=0;
        for(auto &it: nums){
            if(it==0){
                ct0++;
            }else if(it==1){
                ct1++;
            }else{
                ct2++;
            }
        }
        int i = 0;
        while(ct0--){
            nums[i++] = 0;
        }
        while(ct1--){
            nums[i++] = 1;
        }
        while(ct2--){
            nums[i++] = 2;
        }
        return;
    }
};