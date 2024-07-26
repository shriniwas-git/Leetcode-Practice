class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() &&  st.top()>0 && st.top()<abs(asteroids[i])){
                    // cout << st.top() << " " << asteroids[i] << " ";
                    st.pop();
                    // cout << "see";
                }
                if(!st.empty() && st.top()>0 && st.top()==abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || (!st.empty() && st.top()<0)){
                    st.push(asteroids[i]);
                }
                
            }
        }
        int k = st.size();
        vector<int> ans(k);
        int j = k-1;
        while(!st.empty()){
            ans[j] = st.top();
            st.pop();
            j--;
        }
        return ans;

    }
};