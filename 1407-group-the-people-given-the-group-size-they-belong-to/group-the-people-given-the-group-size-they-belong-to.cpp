class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[groupSizes[i]]++;
        }
        for(auto it:mpp){
            it.second = it.second/it.first;
        }
        vector<vector<int>> ans;
        for(auto it: mpp){
            while(it.second--){
                vector<int> temp;
            for(int i=0;i<n;i++){
                if(it.first==groupSizes[i] && temp.size()<it.first){
                    temp.push_back(i);
                    groupSizes[i] = -1;
                }
            }
            if(temp.size()!=0){
            ans.push_back(temp);
            }
            }
        }
        return ans;


    }
};