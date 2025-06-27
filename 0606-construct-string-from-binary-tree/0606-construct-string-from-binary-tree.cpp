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
    string tree2str(TreeNode* root) {
        if(root==NULL)
        return "";
        string rootVal=to_string(root->val);
        string Left=tree2str(root->left);
        string Right=tree2str(root->right);
        if(root->left==NULL&&root->right==NULL)
        return rootVal;
        if(root->left==NULL)
        return rootVal+"()"+"("+Right+")";
        if(root->right==NULL)
        return rootVal+"("+Left+")";
        return rootVal+"("+Left+")"+"("+Right+")";
    }
};