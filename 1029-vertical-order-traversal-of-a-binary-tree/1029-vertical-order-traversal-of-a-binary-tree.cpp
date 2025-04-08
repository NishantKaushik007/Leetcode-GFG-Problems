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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty())
        {
            root=q.front().second.second;
            int vlvl=q.front().first;
            int lvl=q.front().second.first;
            q.pop();
            if(root->left!=NULL)
            q.push({vlvl-1,{lvl+1,root->left}});
            if(root->right!=NULL)
            q.push({vlvl+1,{lvl+1,root->right}});
            mp[vlvl][lvl].insert(root->val);
        }
        for(auto p:mp)
        {
            vector<int>v;
            for(auto q:p.second)
            {
                v.insert(v.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};