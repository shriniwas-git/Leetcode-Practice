class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        map<char,int> mpp;
        int ans = 0;
        while(right<n){
            if(mpp[s[right]]==0){
                mpp[s[right]]++;
                ans = max(ans,right-left+1);
            }else{
                while(mpp[s[right]]!=0){
                    mpp[s[left]]--;
                    left++;
                }
                mpp[s[right]]++;
                ans = max(ans,right-left+1);
            }
            right++;
        }
        return ans;
    }
};