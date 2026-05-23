class Solution {
public:
    // vector<int> toposort(int n, vector<int> adj[])
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses+1];
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        // int indegree[numCourses+1] = {0};
        int v = numCourses;
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo.size()==v;

    }
};