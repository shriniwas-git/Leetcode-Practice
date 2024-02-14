class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int j=0;j<nums.size();j++){
            if(j!=0 && nums[j]==nums[j-1]){
                continue;
            }
        for(int i=j+1;i<nums.size();i++){
            if(i!=j+1 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int sum = nums[i];
            while(left<right){
                long long sum= nums[i];
                sum+=nums[j];
                sum+=nums[left];
                sum+=nums[right];
                if(sum>target){
                    right--;
                }else if(sum<target){
                    left++;
                }else{
                    ans.push_back({nums[j],nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
                }
                
            }
        }
        }
        return ans;
    }
};