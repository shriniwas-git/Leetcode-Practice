class Solution {
public:
    int func(long long mid,vector<int> bloomDay,int m,int k){
        long long ct = 0;
        long long tp=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                tp++;
            }else{
                tp=0;
            }
            if(tp==k){
                ct++;
                tp=0;
            }
        }
        if(ct>=m){
            return 1;
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long p =(long long)m*(long long)k;
        if(p>n){
            return -1;
        }
        long long low = 1;
        long long high = *max_element(bloomDay.begin(),bloomDay.end());
        long long ans = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = func(mid,bloomDay,m,k);
            if(val==1){
                ans = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
};