class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ct5 = 0;
        int ct10 = 0;
        int ct20 = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                ct5++;
            }else if(bills[i]==10){
                if(ct5>0){
                    ct5--;
                    ct10++;
                }else{
                    return false;
                }
            }else if(bills[i]==20){
                if(ct5>=1 && ct10>=1){
                    ct5--;
                    ct10--;
                    ct20++;
                }else if(ct5>=3){
                    ct5-=3;
                    ct20++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};