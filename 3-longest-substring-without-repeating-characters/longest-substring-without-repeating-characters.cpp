class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0; // Initialize to 0 to handle empty string case
        int l = 0, r = 0;
        int n = s.size();
        unordered_set<char> st;

        while (r < n) {
            if (st.find(s[r]) == st.end()) { // If the character is not in the set
                st.insert(s[r]);
                r++;
                ans = max(ans, r - l); // Update the answer
            } else {
                st.erase(s[l]); // Remove the character at position l
                l++;
            }
        }

        return ans;
    }
};