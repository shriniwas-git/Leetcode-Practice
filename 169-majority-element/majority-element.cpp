class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 1;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans){
                ct++;
            }
            else{
                ct--;
                if(ct<0){
                    ans = nums[i];
                    ct++;
                }
            }
        }
        return ans;
    }
};