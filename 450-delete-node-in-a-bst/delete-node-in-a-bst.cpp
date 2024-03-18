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
    TreeNode* rtmost(TreeNode* node){
        if(node->right==NULL){
            return node;
        }
        return rtmost(node->right);
    }
    TreeNode* helper(TreeNode* node){
        if(node->left==NULL){
            return node->right;
        }else if(node->right==NULL){
            return node->left;
        }
        TreeNode* leftone = node->left;
        TreeNode* rtone = node->right;
        TreeNode* ledge = rtmost(node->left);
        ledge->right = node->right;
        return leftone;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};