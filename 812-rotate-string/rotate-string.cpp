class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
        int n = s.size();
        while(n--){
            if(s==goal){
                return true;
            }
            char c = s[s.size()-1];
            string temp = s.substr(0,s.size()-1);
            s = c + temp;
        }
        return false;
    }
};