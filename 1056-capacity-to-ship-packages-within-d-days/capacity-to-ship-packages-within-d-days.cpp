class Solution {
public:
    int func(long long mid,vector<int> &weights,int days){
        long long ct=0;
        long long temp = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid){
                return 0;
            }
            temp+=weights[i];
            if(temp>mid){
                ct++;
                temp=weights[i];
            }else if(temp==mid){
                temp=0;
                ct++;
            }
        }
        if(temp!=0){
            ct++;
        }
        if(ct<=days){
            return 1;
        }
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = 1;
        long long high = 0;
        long long ans = 1;
        for(int i=0;i<weights.size();i++){
            high += weights[i];
        }
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = func(mid,weights,days);
            if(val==1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};