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
    bool isSym(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(p==NULL||q==NULL)
            return p==q;
        return (p->val==q->val)&&isSym(root,p->left,q->right)&&isSym(root,p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSym(root,root->left,root->right);
    }
};