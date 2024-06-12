class Solution {
public:
    bool func(int node,vector<vector<int>> &graph,int color,vector<int> &col){
        col[node]=color;
        for(auto it: graph[node]){
            if(col[it]==-1){
                if(func(it,graph,!color,col)==false){
                    return false;
                }
            }else if(col[it]==col[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // int m = graph[0].size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(func(i,graph,0,col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};