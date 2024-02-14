#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int sum = nums[i];
            while(left<right){
                sum= (nums[i] + nums[left]+nums[right]);
                if(sum>0){
                    right--;
                }else if(sum<0){
                    left++;
                }else{
                    ans.push_back({nums[i],nums[left],nums[right]});
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
        // set<vector<int>> st;
        // for(auto it: ans){
        //     st.insert(it);
        // }
        // vector<vector<int>> ans1;
        // for(auto it: st){
        //     ans1.push_back(it);
        // }
        return ans;
    }
};