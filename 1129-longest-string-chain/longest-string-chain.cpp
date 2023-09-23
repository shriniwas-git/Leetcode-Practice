#include<bits/stdc++.h>
using namespace std;
bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
class Solution {
public:
    bool checkPossible(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int first=0;
        int second = 0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++;
            }

        }
        if(first==s1.size() && second==s2.size()){
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(1+dp[prev]>dp[i] && checkPossible(words[i],words[prev])){
                    dp[i] = 1+dp[prev];
                    // maxi = (1 + dp[prev],maxi);
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};