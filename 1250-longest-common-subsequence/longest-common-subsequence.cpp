class Solution {
public:
    int func(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(text1[ind1]==text2[ind2]){
            return 1 + func(ind1-1,ind2-1,text1,text2,dp);
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        return dp[ind1][ind2] = max(func(ind1-1,ind2,text1,text2,dp),func(ind1,ind2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return func(n-1,m-1,text1,text2,dp);
        vector<int> prev(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            vector<int> cur(m+1,0);
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    cur[ind2] = 1 + prev[ind2-1];
                    continue;
                }

                cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};