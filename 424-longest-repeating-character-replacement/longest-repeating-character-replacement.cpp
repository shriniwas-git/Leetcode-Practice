class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        vector<int> hash(26,0);
        int  mrcf= 0; //max_rep_char_freq
        int ans = 0;
        while(right<n){
            hash[s[right]-'A']++;
            mrcf = max(mrcf,hash[s[right]-'A']);
            //Distinct char count --> right-left+1 - (mrcf) --> length-mrcf
            if(right<n && ((right-left+1)-mrcf>k)){
                hash[s[left]-'A']--;
                int temp_max = 0;
                for(int i=0;i<26;i++){
                    temp_max = max(temp_max,hash[i]);
                }
                left++;
                mrcf = temp_max;
            }
            if((right-left+1)-mrcf<=k){
                ans = max(ans,right-left+1);
            }
            right++;
        }
        return ans;
    }
};