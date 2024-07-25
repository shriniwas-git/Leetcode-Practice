class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> ans(n,-1);
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums2[i]] = i;
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
                st.push(nums2[i]);
            }else{
                ans[i] = st.top();
                st.push(nums2[i]);
            }
        }
        for(auto it: ans){
            cout << it << " ";
        }
        cout << endl;
        vector<int> res(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            res[i] = ans[mpp[nums1[i]]];
        }
        return res;

    }
};