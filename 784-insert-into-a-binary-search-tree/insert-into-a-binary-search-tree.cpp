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
        TreeNode* last = root;
        TreeNode* prev = root;
        while(last!=NULL){
            prev = last;
            if(last->val>val){
                last = last->left;
            }else{
                last = last->right;
            }
        }
        TreeNode* nnode = new TreeNode(val);
        if(prev==NULL){
            return nnode;
        }
        if(prev->val>val){
            prev->left = nnode;
        }else{
            prev->right = nnode;
        }
        return root;
    }
};