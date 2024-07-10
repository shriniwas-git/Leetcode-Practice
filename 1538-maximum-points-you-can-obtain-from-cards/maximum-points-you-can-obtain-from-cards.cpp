class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int presum = 0;
        for(int i=0;i<k;i++){
            presum+=cardPoints[i];
        }
        int ans = presum;
        int n = cardPoints.size();
        for(int i=0;i<cardPoints.size();i++){
            presum-=cardPoints[i];
            presum+=cardPoints[(i+k)%n];
            cout << presum << endl;
            if((i+1)>=n-k){
            ans = max(ans,presum);
            }
        }
        return ans;
    }
};