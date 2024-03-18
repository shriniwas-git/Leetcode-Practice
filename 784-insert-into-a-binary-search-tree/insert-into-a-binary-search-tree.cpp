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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nnode = new TreeNode(val);
        if(root==NULL){
            return nnode;
        }
        TreeNode* temp = root;
        TreeNode* prev = root;
        while(root){
            prev = root;
            if(root->val>val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        
        if(prev->val>val){
            prev->left = nnode;
        }else{
            prev->right = nnode;
        }
        return temp;
    }
};