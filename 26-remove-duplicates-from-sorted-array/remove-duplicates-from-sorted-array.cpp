class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mark;
        vector<int> ans;
        for(auto it: nums){
            if(mark[it]==0){
                ans.push_back(it);
            }
            mark[it]++;
        }
        for(int i=0;i<ans.size();i++){
            nums[i] = ans[i];
        }
        return ans.size();
    }
};