class Solution {
public:
    bool func(int ind,vector<int> &stones,int k,vector<vector<int>> &dp){
        if(ind==stones.size()-1){
            return true;
        }
        int n = stones.size();
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        bool a =false;
        bool b = false;
        bool c= false;
        for(int j = ind+1;j<n;j++){
            if(stones[j]-stones[ind]==k-1){
                a = func(j,stones,k-1,dp);
                break;
            }
        }
        for(int j = ind+1;j<n;j++){
           if(stones[j]-stones[ind]==k){
            b = func(j,stones,k,dp);
            break;
        }
        }
        for(int j = ind+1;j<n;j++){
           if(stones[j]-stones[ind]==k+1){
            c = func(j,stones,k+1,dp);
            break;
        }
        }
        
        return dp[ind][k] = a|b|c;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int k = *max_element(stones.begin(),stones.end());
        if(stones[1]-stones[0]!=1){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        bool ans = func(1,stones,1,dp);
        return ans;
    }
};