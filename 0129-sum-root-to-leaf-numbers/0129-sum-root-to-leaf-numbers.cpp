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
    int rootToLeafSum(TreeNode* root,int sum)
    {
        if(root==NULL)
            return 0;
        sum=sum*10+root->val;
        if(root->left==NULL&&root->right==NULL)
            return sum;
        int l=rootToLeafSum(root->left,sum);
        int r=rootToLeafSum(root->right,sum);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return rootToLeafSum(root,0);
    }
};