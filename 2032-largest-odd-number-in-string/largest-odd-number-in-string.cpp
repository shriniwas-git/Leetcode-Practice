class Solution {
public:
    string largestOddNumber(string num) {
        int j=-1;
        for(int i=num.size();i>=0;i--){
            int dig = num[i] - '0';
            if(dig%2){
                j=i;
                break;
            }
        }
        string ans = "";
        if(j==-1){
            return ans;
        }
        for(int i=0;i<=j;i++){
            ans+=num[i];
        }
        return ans;
    }
};