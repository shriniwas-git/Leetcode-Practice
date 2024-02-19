class Solution {
public:
    // int func(long long mid,vector<int> &arr,int k){

    // }
    int findKthPositive(vector<int>& arr, int k) {
        long long low = 0;
        long long high = arr.size()-1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long miss = arr[mid] - (mid+1);
            if(miss>=k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return (high+1+k);
    }
};