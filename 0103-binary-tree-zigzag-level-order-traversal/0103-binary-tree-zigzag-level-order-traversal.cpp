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
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool left=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level(n);
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                int ind=i;
                if(left==false)
                    ind=n-i-1;
                level[ind]=root->val;
                if(root->left!=NULL)
                    q.push(root->left);
                if(root->right!=NULL)
                    q.push(root->right);
            }
            left=!left;
            ans.push_back(level);
        }
        return ans;
    }
};