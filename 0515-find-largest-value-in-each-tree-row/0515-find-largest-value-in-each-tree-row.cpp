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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int maxi=INT_MIN;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                root=q.front();
                q.pop();
                if(root->left!=NULL)
                    q.push(root->left);
                if(root->right!=NULL)
                    q.push(root->right);
                maxi=max(maxi,root->val);
            }
            res.push_back(maxi);
        }
        return res;
    }
};