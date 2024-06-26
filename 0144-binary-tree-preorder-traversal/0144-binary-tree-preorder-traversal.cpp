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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        if(root==NULL)
            return pre;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            s.pop();
            if(root->right!=NULL)
                s.push(root->right);
            if(root->left!=NULL)
                s.push(root->left);
            pre.push_back(root->val);
        }
        return pre;
    }
};