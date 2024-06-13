class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        pair<int,int> src;
        src = {0,0};
        pair<int,int> dest;
        dest = {n-1,m-1};
    if(matrix[src.first][src.second]!=0) return -1;
    if (src.first == dest.first &&
        src.second == dest.second) {
      return 1;
    }
    
    vector<vector<int>> dist(n, vector<int> (m,1e9));
    q.push({0,{src.first,src.second}});
    dist[src.first][src.second] = 0;
    int dr[] = {-1,0,1,0,-1,-1,1,1};
    int dc[] = {0,1,0,-1,-1,1,-1,1};
    
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if(r==dest.first && c ==dest.second){
                    return 1+dis;
                }
        for(int i=0;i<8;i++){
            int nrow = r + dr[i];
            int ncol = c+ dc[i];
            if(nrow>=0 && nrow<n && ncol>=0  &&ncol<m && matrix[nrow][ncol]==0 && dist[nrow][ncol]>1+dis){
                dist[nrow][ncol] = 1+dis;
                
                q.push({1+dis,{nrow,ncol}});
            }
        }
    }
    return -1;
    }
};