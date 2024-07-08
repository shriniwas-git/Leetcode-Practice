class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cto = 0;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cto++;
                if(cto>1 || temp.size()>0){
                    temp+=s[i];
                }
            }else{
                cto--;
                if(cto==0){
                    ans+=temp;
                    temp = "";
                }else{
                    temp+=')';
                }
            }
        }
        return ans;
    }
};