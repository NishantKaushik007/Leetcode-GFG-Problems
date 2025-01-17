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
        map<int,map<int,multiset<int>>>m;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                root=q.front().second.second;
                int vlvl=q.front().first;
                int hlvl=q.front().second.first;
                q.pop();
                if(root->left!=NULL)
                q.push({vlvl-1,{hlvl+1,root->left}});
                if(root->right!=NULL)
                q.push({vlvl+1,{hlvl+1,root->right}});
                m[vlvl][hlvl].insert(root->val);
            }
        }
        for(auto it:m)
        {
            vector<int>v;
            for(auto p:it.second)
            {
                v.insert(v.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};