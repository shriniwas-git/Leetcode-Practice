class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen = 1;
        
        function<int(int, int)> dfs = [&](int r, int c) {
            if(dp[r][c] != -1) return dp[r][c];
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            int maxPath = 1;
            
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                    maxPath = max(maxPath, 1 + dfs(nr, nc));
                }
            }
            
            dp[r][c] = maxPath;
            return dp[r][c];
        };
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(i, j));
            }
        }
        
        return maxLen;
    }
};