class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int val = (arr[i]*((static_cast<long long>(nse[i]-i)*(i-pse[i]))))%mod;
            ans = (ans + val)%mod;
        }
        return ans%mod;
    }
};