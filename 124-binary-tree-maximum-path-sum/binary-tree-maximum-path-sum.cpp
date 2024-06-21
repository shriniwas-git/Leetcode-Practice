/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int lh =pathSum(root->left,maxi);
        int rh = pathSum( root->right,maxi);
        if(lh<0){
            lh = 0;
        }
        if(rh<0){
            rh=0;
        }
        maxi = max(maxi,root->val+lh+rh);
        return root->val + max(max(lh,rh),0);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathSum(root,sum);
        return sum;
    }
};