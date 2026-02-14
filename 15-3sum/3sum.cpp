class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>  ans;
        for(int i=0;i<n;i++){
            if(i>=1 && nums[i]==nums[i-1]){
                continue;
            }
            int el = nums[i];
            int left = i+1, right = n-1;
            while(left<right){
                int val = el + nums[left] + nums[right];
                if(val==0){
                    ans.push_back({el,nums[left],nums[right]});
                    left++;right--;
                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }else if(val>0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ans;
    }
};