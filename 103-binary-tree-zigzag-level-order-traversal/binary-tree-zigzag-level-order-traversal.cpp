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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        int l = 0;
        while(!q.empty()){
            int len = q.size();
            int length = q.size();
            vector<int> level(len);
            while(len--){
                auto node = q.front();
                q.pop();
                if(l==1){
                level[len] = node->val;
                }else{
                    level[length-len-1] = node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(l==1){
                l=0;
            }else{
                l=1;
            }
            ans.push_back(level);

        }
        return ans;
    }
};