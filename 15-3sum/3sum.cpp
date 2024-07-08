class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int j = i+1;
            int k =n-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k])==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<n && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(k>0 && nums[k+1]==nums[k]){
                        k--;
                    }
                }else if((nums[i]+nums[j]+nums[k])>0){
                    k--;
                }else{
                    j++;
                }
                
            }
        }
        return ans;
    }
};