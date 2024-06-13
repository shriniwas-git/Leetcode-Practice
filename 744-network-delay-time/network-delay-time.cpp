class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
vector<vector<pair<int,int>>>adj(n+1);
int s = times.size();
int mx = 0;
for(int i = 0; i<s; i++)
{
int source = times[i][0];
int dest = times[i][1];
int dist = times[i][2];
adj[source].push_back({dist,dest});

    }
    priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> ds(n+1);
    for(int i = 0; i<=n; i++)
    {
        ds[i] = 1e9;
        
    }
    ds[k] = 0;
    pq.push({0,k});
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node])
        {
            int adjdist = it.first;
            int adjnode = it.second;
            int sum = dist+adjdist;
            if(ds[adjnode] > sum)
            {
                ds[adjnode] = sum;
                pq.push({sum,it.second});
            }
            
            
        }
    }
    for(int j = 1; j<= n ;j++)
    {
        if(ds[j] == 1e9 )
        {
            return -1;
        }
        mx = max(mx,ds[j]);
        
    }
    
    return mx;
}
};