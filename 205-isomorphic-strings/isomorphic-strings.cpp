class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpp;
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> val(200,0);
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(t[i]!=mpp[s[i]]){
                    return false;
                }
            }else{
                    if(val[t[i]]==1){
                        return false;
                    }
                    mpp[s[i]] = t[i];
                    val[t[i]] = 1;
            }
        }
        
        return true;
    }
};