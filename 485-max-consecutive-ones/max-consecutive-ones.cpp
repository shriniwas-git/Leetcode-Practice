class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int tct = 0;
        for(auto &it: nums){
            if(it==1){
                tct++;
                ans = max(ans,tct);
            }else{
                tct = 0;
            }
        }
        return ans;
    }
};