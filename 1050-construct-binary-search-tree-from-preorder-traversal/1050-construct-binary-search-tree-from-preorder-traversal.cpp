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
    TreeNode* buildBst(vector<int>& preorder,int& index,int upperBound)
    {
        if(index==preorder.size()||preorder[index]>upperBound)
        return NULL;
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left=buildBst(preorder,index,root->val);
        root->right=buildBst(preorder,index,upperBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildBst(preorder,i,INT_MAX);
    }
};