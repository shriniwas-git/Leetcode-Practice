class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int sum =0;
        int f0=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            f0 += i*nums[i];
        }
        int f1 = 0;
        int ans = f0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            f1 = f0 + sum - (n)*nums[n-i];
            ans = max(ans,f1);
            f0 = f1;
        }
        return ans;
    }
};