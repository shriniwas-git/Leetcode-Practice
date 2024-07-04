class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1 = 0;
        int ct2 = 0;
        int el1 = INT_MIN,el2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                ct1++;
            }else if(nums[i]==el2){
                ct2++;
            }else if(ct1==0){
                el1 = nums[i];
                ct1++;
            }else if(ct2==0){
                el2 = nums[i];
                ct2++;
            }else{
                ct1--;
                ct2--;
            }
        }
        vector<int> ls; // list of answers

        // Manually check if the stored elements in
        // el1 and el2 are the majority elements:
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }
        int n = nums.size();

        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini) ls.push_back(el2);
        return ls;

        }
};