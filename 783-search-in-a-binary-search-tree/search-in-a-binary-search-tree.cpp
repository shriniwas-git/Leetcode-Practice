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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = NULL;
        while(root!=NULL){
            if(root->val==val){
                node = root;
                break;
            }
            if(root->left){
                if(root->val>val){
                    root = root->left;
                    continue;
                }
            }
            if(root->right){
                if(root->val<val){
                    root = root->right;
                    continue;
                }
            }
            root=NULL;
        }
        return node;
    }
};