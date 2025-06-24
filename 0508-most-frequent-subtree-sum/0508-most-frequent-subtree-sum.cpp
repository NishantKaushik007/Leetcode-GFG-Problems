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
    int sumSubTree(TreeNode* root,unordered_map<int,int>& sumFreq,int& maxFreq)
    {
        if(root==NULL)
        return 0;
        int lSum=sumSubTree(root->left,sumFreq,maxFreq);
        int rSum=sumSubTree(root->right,sumFreq,maxFreq);
        int currSum=root->val+lSum+rSum;
        sumFreq[currSum]++;
        maxFreq=max(maxFreq,sumFreq[currSum]);
        return currSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>sumFreq;
        int maxFreq=0;
        sumSubTree(root,sumFreq,maxFreq);
        for(auto it:sumFreq)
        {
            int sum=it.first;
            int freq=it.second;
            if(freq==maxFreq)
            ans.push_back(sum);
        }
        return ans;
    }
};