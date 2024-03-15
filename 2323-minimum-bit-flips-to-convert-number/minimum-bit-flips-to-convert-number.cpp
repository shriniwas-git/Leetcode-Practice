class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct = 0;
        int req = start^goal;
        while(req!=0){
            req = req&(req-1);
            ct++;
        }
        return ct;
    }
};