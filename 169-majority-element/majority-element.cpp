class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 1;
        int el = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=el){
                ct--;
                if(ct==0){
                    el = nums[i];
                    ct=1;
                }
            }else{
                ct++;
            }
        }
        return el;
    }
};