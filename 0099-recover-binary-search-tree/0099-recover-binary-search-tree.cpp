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
TreeNode* first=NULL,*mid=NULL,*last=NULL,*prev=NULL;
public:
    void findWrong(TreeNode* root)
    {
        if(root==NULL)
        return;
        findWrong(root->left);
        if(prev&&prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        findWrong(root->right);
    }
    void recoverTree(TreeNode* root) {
        findWrong(root);
        if(first&&last)
        swap(first->val,last->val);
        else if(first&&mid)
        swap(first->val,mid->val);
    }
};