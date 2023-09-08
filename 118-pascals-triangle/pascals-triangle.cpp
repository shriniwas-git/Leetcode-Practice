class Solution {
public:
    int fncr(int n,int r){
        int res=1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res = res /(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> ok;
            for(int j=0;j<=i;j++){
                ok.push_back(fncr(i,j));
            }
            ans.push_back(ok);
        }
        return ans;
    }
};