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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth=0;
        if(root==NULL)
        return maxWidth;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            int left,right,firstInd=q.front().second;
            for(int i=0;i<n;i++)
            {
                root=q.front().first;
                int ind=q.front().second-firstInd;
                q.pop();
                if(i==0)
                left=ind-firstInd;
                if(i==n-1)
                right=ind-firstInd;
                if(root->left!=NULL)
                q.push({root->left,(long long)2*ind+1});
                if(root->right!=NULL)
                q.push({root->right,(long long)2*ind+2});
            }
            maxWidth=max(maxWidth,right-left+1);
        }
        return maxWidth;
    }
};