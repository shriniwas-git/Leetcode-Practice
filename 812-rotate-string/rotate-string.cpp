#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        if (s == goal) {
            return true;
        }
        string whole = s + s;
        // Use `find` to check if `goal` is a substring of `whole`
        return whole.find(goal) != string::npos;
    }
};