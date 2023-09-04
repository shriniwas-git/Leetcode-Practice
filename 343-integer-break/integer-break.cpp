class Solution {
public:
    int f(int n){
        if(n<=3){
            return n;
        }
        // return f(n/2)*f(n/2 + n%2);
        int ans = 1;
        while(n>4){
            ans*=3;
            n-=3;
        }
        return ans*n;
    }
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int ans = f(n);
        return ans;
    }
};