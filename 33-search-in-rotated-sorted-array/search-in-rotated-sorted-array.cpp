class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                ans = mid;
                return ans;
            }
            if(arr[low]<=arr[mid]){
                if(target>=arr[low] && target<=arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(target>=arr[mid] && target<=arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return ans;
    }
};