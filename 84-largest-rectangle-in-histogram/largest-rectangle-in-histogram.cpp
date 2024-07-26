class Solution {
public:
    vector<int> findNSE(vector<int> &heights){
        int n = heights.size();
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int> &heights){
        int n = heights.size();
        vector<int> pse(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse,pse;
        nse = findNSE(heights);
        pse = findPSE(heights);
        int sum = 0;
        for(int i=0;i<heights.size();i++){
            sum = max(sum,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return sum;
    }
};