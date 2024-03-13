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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(root==NULL){
            return 0;
        }
        q.push({root,0});
        int width = 1;

        while(!q.empty()){
            int size= q.size();
            auto n1 = q.front();
            long long int vali = n1.second;
            int first,last;
            for(int i=0;i<size;i++){
                auto node = q.front().first;
                auto val = q.front().second - vali;
                q.pop();
                
                if(i==0){
                    first = val;
                }
                if(i==size-1){
                    last = val;
                }
                if(node->left){
                    q.push({node->left,2*val+1});
                }
                if(node->right){
                    q.push({node->right,2*val+2});
                }
            }
            width = max(width,last-first+1);
        }
        return width;
    }
};