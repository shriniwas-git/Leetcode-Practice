class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        dis[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curDiff = it[0];
            int curRow = it[1];
            int curCol = it[2];
            if(curRow==n-1 && curCol==m-1){
                return dis[curRow][curCol];
            }
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nRow = curRow + dr[i];
                int nCol = curCol + dc[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m ){
                    int newDiff = abs(heights[nRow][nCol] - heights[curRow][curCol]);
                    newDiff = max(newDiff,curDiff);
                    if(newDiff<dis[nRow][nCol]){
                        dis[nRow][nCol] = newDiff;
                        pq.push({newDiff,nRow,nCol});
                    }
                }
            }

        }
        return -1;

    }
};