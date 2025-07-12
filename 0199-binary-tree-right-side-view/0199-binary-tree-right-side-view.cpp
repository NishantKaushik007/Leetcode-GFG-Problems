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
    void getRView(TreeNode* root,int lvl,vector<int>& rView)
    {
        if(root==NULL)
        return;
        if(lvl==rView.size())
        rView.push_back(root->val);
        getRView(root->right,lvl+1,rView);
        getRView(root->left,lvl+1,rView);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rView;
        int lvl=0;
        getRView(root,lvl,rView);
        return rView;
    }
};