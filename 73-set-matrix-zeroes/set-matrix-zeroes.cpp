class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> colindex,rowindex;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rowindex.insert(i);
                    colindex.insert(j);
                }
            }
        }
        for(auto &it: rowindex){
            for(int j=0;j<m;j++){
                matrix[it][j]=0;
            }
        }
        for(auto &it: colindex){
            for(int j=0;j<n;j++){
                matrix[j][it]=0;
            }
        }
        return ;

    }
};