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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->left!=NULL)
            {
                q.push(root->left);
                if(root->left->left!=NULL&&root->val%2==0)
                sum+=root->left->left->val;
                if(root->left->right!=NULL&&root->val%2==0)
                sum+=root->left->right->val;
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
                if(root->right->left!=NULL&&root->val%2==0)
                sum+=root->right->left->val;
                if(root->right->right!=NULL&&root->val%2==0)
                sum+=root->right->right->val;
            }
        }
        return sum;
    }
};