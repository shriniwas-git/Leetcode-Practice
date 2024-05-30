class Solution {
public:
    int myAtoi(std::string s) {
        std::string filtered = "";
        int sread = 0; // flag for reading sign
        int dread = 0; // flag for reading digits
        
        // Step 1: Filter the input string
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ' && sread == 0 && dread == 0) {
                continue; // skip leading spaces
            } else if((s[i] == '-' || s[i] == '+') && sread == 0 && dread == 0) {
                sread = 1; // read the sign
                filtered += s[i];
            } else if(s[i] >= '0' && s[i] <= '9') {
                dread = 1; // read digits
                filtered += s[i];
            } else {
                break; // stop on any non-digit character
            }
        }
        
        if(filtered.empty() || (filtered.size() == 1 && (filtered[0] == '-' || filtered[0] == '+'))) {
            return 0; // return 0 if filtered string is empty or contains only a sign
        }
        
        // Step 2: Convert the filtered string to an integer
        long long ans = 0;
        int startIndex = (filtered[0] == '-' || filtered[0] == '+') ? 1 : 0;
        for(int i = startIndex; i < filtered.size(); i++) {
            ans = ans * 10 + (filtered[i] - '0');
            if(ans > INT_MAX) {
                return (filtered[0] == '-') ? INT_MIN : INT_MAX;
            }
        }
        
        ans = (filtered[0] == '-') ? -ans : ans;
        
        // Ensure the result is within the 32-bit signed integer range
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return ans;
    }

};