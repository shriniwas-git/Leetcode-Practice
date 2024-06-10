class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[sr][sc];
        image[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==iniColor && (iniColor!=color)){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};