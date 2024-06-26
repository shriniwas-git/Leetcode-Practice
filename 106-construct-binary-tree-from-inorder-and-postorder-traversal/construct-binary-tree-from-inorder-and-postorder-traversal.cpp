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
    TreeNode* build(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart
    ,int postEnd,map<int,int> &mpp){
        if(inStart>inEnd || postStart>postEnd){
            return NULL;
        }
        int value = postorder[postEnd];
        TreeNode* root = new TreeNode();
        root->val = value;
        int indOfRoot = mpp[root->val];
        int inSizeLeft = indOfRoot-inStart;
        int inSizeRight = inEnd - indOfRoot;
        root->left = build(inorder,inStart,indOfRoot-1,postorder,postStart,postStart+inSizeLeft-1,mpp);
        root->right = build(inorder,indOfRoot+1,inEnd,postorder,postStart+inSizeLeft,postEnd-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};