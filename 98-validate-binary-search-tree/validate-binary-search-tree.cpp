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
    void in(TreeNode* root,vector<int> &inorder){
        if(root==NULL){
            return;
        }
        in(root->left,inorder);
        inorder.push_back(root->val);
        in(root->right,inorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        in(root,inorder);
        if(inorder.size()<=1){
            return true;
        }
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]){
                return false;
            }
        }
        return true;
    }
};