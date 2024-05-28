class Solution {
public:
    int func(int mid,vector<int>& piles,int h){
        long long int ct = 0;
        for(int i=0;i<piles.size();i++){
            long long int val = piles[i]/mid;
            if(piles[i]%mid!=0){
                val++;
            }
            ct += val;
        }
        if(ct<=h){
            return 1;
        }
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int val = func(mid,piles,h);
            if(val==1){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid  + 1;
            }
        }
        return ans;
    }
};