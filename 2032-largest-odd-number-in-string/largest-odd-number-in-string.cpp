class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            char c = num[i];
            int val = c - '0';
            if(val%2){
                return num;
            }else{
                num.pop_back();
            }
        }
        return num;
    }
};