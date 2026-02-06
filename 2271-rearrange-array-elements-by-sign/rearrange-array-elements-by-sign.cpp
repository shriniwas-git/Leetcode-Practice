class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(auto &it: nums){
            if(it<0){
                neg.push_back(it);
            }else{
                pos.push_back(it);
            }
        }
        for(int i=0;i<nums.size()/2;i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        return nums;
    }
};