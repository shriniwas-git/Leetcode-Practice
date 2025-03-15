class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(auto it: nums){
            s.insert(it);
        }
        int n = s.size();
        int j = 0;
        for(auto it: s){
            nums[j++] = it;
        }
        return n;
    }
};