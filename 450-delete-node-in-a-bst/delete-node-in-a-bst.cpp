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
    TreeNode* LRM(TreeNode* node){
        if(node->right==NULL){
            return node;
        }
        return LRM(node->right);
    }
    TreeNode* helper(TreeNode* node){
        if(node->right==NULL){
            return node->left;
        }
        if(node->left==NULL){
            return node->right;
        }
        TreeNode* rightChild = node->right;
        TreeNode* leftChild = node->left;
        TreeNode* leftRightMost = LRM(leftChild);
        leftRightMost->right = rightChild;
        return leftChild;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root!=NULL){
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