class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mpp;
        if(s.size()!=t.size()){
            return false;
        }
        for(auto c: s){
            mpp[c]++;
        }
        for(auto c: t){
            if(mpp[c]<=0){
                return false;
            }
            mpp[c]--;
        }
        return true;
    }
};