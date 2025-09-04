class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int n = nums.size();
        int ct = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==el){
                ct++;
            }else{
                ct--;
                if(ct==0){
                    el = nums[i];
                    ct=1;
                }
            }
        }
        return el;

    }
};