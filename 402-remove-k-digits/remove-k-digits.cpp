class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(k==num.size()){
            return "0";
        }
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                k--;
                st.pop();
            }
            
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            k--;
            st.pop();
        }
        int n = st.size();
        string ans(n,'0');
        int j = n-1;
        while(!st.empty()){
            ans[j] = st.top();
            j--;
            st.pop();
        }
        int fl = -1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                fl = i;
                break;
            }
        }
        string answer = "0";
        if(fl==-1){
            return answer;
        }
        return ans.substr(fl);
        return ans;
    }
};