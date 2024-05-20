class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=1;
        int mlem = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=mlem){
                ct--;
                if(ct==0){
                    ct=1;
                    mlem = nums[i];
                }
            }else{
                ct++;
            }
        }
        return mlem;
    }
};