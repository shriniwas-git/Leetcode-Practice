class Solution {
public:
    int func(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        int n = text1.size();
        int m = text2.size();
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+ func(i+1,j+1,text1,text2,dp);
        }
        return dp[i][j] = max(func(i,j+1,text1,text2,dp),func(i+1,j,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans = func(0,0,text1,text2,dp);
        return ans;
    }
};