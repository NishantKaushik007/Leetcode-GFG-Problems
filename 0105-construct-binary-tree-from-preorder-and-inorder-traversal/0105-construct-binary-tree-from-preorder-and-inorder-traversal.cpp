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
    TreeNode* solve(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& inMap)
    {
        if(preStart>preEnd||inStart>inEnd)
        return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=inMap[root->val];
        int numLeft=inRoot-inStart;
        root->left=solve(preStart+1,preStart+numLeft,inStart,inRoot-1,preorder,inorder,inMap);
        root->right=solve(preStart+numLeft+1,preEnd,inRoot+1,inEnd,preorder,inorder,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;
        return solve(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,inMap);
    }
};