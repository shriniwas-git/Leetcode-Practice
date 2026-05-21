class Solution {
public:
    int hammingWeight(int n) {

        int k = n;
        int ans = 0;
        while(k!=0){
            if(k%2!=0){
                ans++;
            }
            k = k>>1;
        }
        return ans;
        
    }
};