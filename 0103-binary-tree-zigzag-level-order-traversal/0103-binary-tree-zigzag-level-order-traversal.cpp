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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>lvl(n);
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                int ind=(leftToRight)?i:n-i-1;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                lvl[ind]=root->val;
            }
            leftToRight=!leftToRight;
            res.push_back(lvl);
        }
        return res;
    }
};