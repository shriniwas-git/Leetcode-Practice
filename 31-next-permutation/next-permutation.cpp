#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int bp = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                bp = i-1;
                break;
            }
            
        }
        if(bp==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>bp;i--){
            if(nums[i]>nums[bp]){
                swap(nums[i],nums[bp]);
                break;
            }
        }
        // swap(nums[bp],nums[minind]);
        reverse(nums.begin()+bp+1,nums.end());
    }
};