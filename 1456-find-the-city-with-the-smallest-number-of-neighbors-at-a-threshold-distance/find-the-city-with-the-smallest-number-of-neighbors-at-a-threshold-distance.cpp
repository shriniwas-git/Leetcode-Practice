class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mat[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                mat[i][j] = 0;
                }else{
                    mat[i][j] = 1e9;
                }
            }
        }
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // if(mat[i][j]==1e9){
                    //     continue;
                    // }
                    // if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                    mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
                    // }
                }
            }
        }
        vector<int> ct (n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    ct[i]++;
                }
            }
        }
        int mx = *min_element(ct.begin(),ct.end());
        for(int i=n-1;i>=0;i--){
            if(ct[i]!=0 && ct[i]==mx){
                return i;
            }
        }
        return 0;
    }
};