class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for (auto c : s) {
            mpp[c]++;
        }

        // Create a vector of pairs and transfer the map data to it
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        // Sort the vector based on the frequency (second element of pair)
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;  // Sort in descending order of frequency
        });

        string ans = "";
        // Construct the result string based on the sorted vector
        for (auto it : vec) {
            int ct = it.second;
            char ch = it.first;
            while (ct--) {
                ans += ch;
            }
        }

        cout << ans << endl;
        return ans;
    }
};