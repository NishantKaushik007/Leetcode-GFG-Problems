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
    int solve(TreeNode* root,int parent,int gparent)
    {
        if(root==NULL)
        return 0;
        return solve(root->left,root->val,parent)+solve(root->right,root->val,parent)+(gparent%2?0:root->val);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root,-1,-1);
    }
};