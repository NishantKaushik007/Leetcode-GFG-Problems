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
    TreeNode* bst(int& ind,vector<int>& preorder,int upperLimit)
    {
        if(ind==preorder.size()||preorder[ind]>upperLimit)
        return NULL;
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=bst(ind,preorder,root->val);
        root->right=bst(ind,preorder,upperLimit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(i,preorder,INT_MAX);
    }
};