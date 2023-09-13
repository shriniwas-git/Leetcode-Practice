class Solution {
public:
    bool func(vector<int> &col,vector<int> adj[],int n,int cur){
        queue<int> q;
        q.push(cur);
        col[cur]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(col[it]==-1){
                    col[it] = !col[node];
                    q.push(it);
                }else if(col[it]==col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(func(col,adj,n,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};