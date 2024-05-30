class Solution {
public:
    int maxDepth(string s) {
        int ct=0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ct++;
                ans = max(ans,ct);
            }else if(s[i]==')'){
                ct--;
            }
        }
        return ans;
    }
};