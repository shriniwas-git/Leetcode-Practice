class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cto = 0;
        int ctc = 0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cto++;
            }else if(s[i]==')'){
                ctc++;
            }
            if(cto==ctc){
                if(cto!=1){
                    ans+=temp;
                    cout << i << " " << temp << endl;
                    temp="";
                }
                cto=0;
                ctc=0;
                continue;
                
            }
            if(cto==1){
                continue;
            }
            
            temp+=s[i];
        }
        return ans;
    }
};