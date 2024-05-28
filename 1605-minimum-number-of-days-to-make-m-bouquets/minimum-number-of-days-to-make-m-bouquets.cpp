class Solution {
public:
    int func(int mid,vector<int>& bloomDay,int m,int k){
        int ct = 0;
        int tc = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(tc==k){
                tc=0;
                ct++;
            }
            if(bloomDay[i]<=mid){
                tc++;
            }else{
                tc=0;
            }
        }
        if(tc==k){
            ct++;
        }
        cout << mid << " " << ct << endl;
        if(ct>=m){
            return 1;
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int val = func(mid,bloomDay,m,k);
            if(val==1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};