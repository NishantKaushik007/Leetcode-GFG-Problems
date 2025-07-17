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
    int dfs(TreeNode* root,long currSum,int targetSum,unordered_map<long,int>& prefixSum)
    {
        if(root==NULL)
        return 0;
        currSum+=root->val;
        int count=prefixSum[currSum-targetSum];
        prefixSum[currSum]++;
        count+=dfs(root->left,currSum,targetSum,prefixSum);
        count+=dfs(root->right,currSum,targetSum,prefixSum);
        prefixSum[currSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int>prefixSum;
        prefixSum[0]=1;
        return dfs(root,0,targetSum,prefixSum);
    }
};