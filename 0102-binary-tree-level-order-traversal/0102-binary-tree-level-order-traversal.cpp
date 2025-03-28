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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>lvl;
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                if(root->left!=NULL)
                q.push(root->left);
                if(root->right!=NULL)
                q.push(root->right);
                lvl.push_back(root->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};