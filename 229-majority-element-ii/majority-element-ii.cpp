class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1=0;
        int ct2=0;
        int el1=0,el2=0;
        for(int i=0;i<nums.size();i++){
            if(ct1==0 && nums[i]!=el2){
                ct1++;
                el1=nums[i];
            }else if(ct2==0 && nums[i]!=el1){
                ct2++;
                el2 = nums[i];
            }else if(nums[i]==el1){
                ct1++;
            }else if(nums[i]==el2){
                ct2++;
            }else{
                ct1--;
                ct2--;
            }
        }
        int n = nums.size();
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                c1++;
            }else if(nums[i]==el2){
                c2++;
            }
        }
        if(c1>n/3 && c2>n/3){
        return {el1,el2};
        }else if(c1>n/3){
            return {el1};
        }else if(c2>n/3){
        return {el2};
        }
        return {};
    }
};