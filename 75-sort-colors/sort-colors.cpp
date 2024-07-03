class Solution {
public:
    void sortColors(vector<int>& arr) {
        // 0 low-1 low mid-1 high+1 n-1 {0,1,2}
        int low = 0, mid = 0,high = arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else if(arr[mid]==2){
                swap(arr[high],arr[mid]);
                high--;
            }
        }

    }
};