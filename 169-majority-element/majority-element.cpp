class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int ans = nums[0];
        for(auto it: nums){
            mpp[it]++;
            if(it!=ans){
                if(mpp[ans]<mpp[it]){
                    ans = it;
                }
                // ans = max();
            }
        }
        return ans;

    }
};