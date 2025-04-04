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
    void solve(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& inMap)
    {
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inPos=inMap[root->val];
        int left=inPos-1;
        int right=inPos+1;
        root->left=solve(preStart+1,preEnd,inStart,left,preorder,inorder,inMap);
        root->right=solve(preStart+1,preEnd,right,left,preorder,inorder,inMap);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;
        solve(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};