class Solution {
public:
    int func(long long mid,vector<int> &piles,int h){
        long long ct=0;
        for(int i=0;i<piles.size();i++){
            long long val = piles[i]/mid;
            if(piles[i]%mid!=0){
                val+=1;
            }
            ct+=val;
        }
        // cout << ct <<" " << mid << endl;
        if(ct>h){
            return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        long long ans =1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = func(mid,piles,h);
            if(val==1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};