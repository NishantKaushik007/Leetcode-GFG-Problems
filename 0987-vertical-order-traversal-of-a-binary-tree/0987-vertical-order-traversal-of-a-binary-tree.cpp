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
        //verticle    level      node->val
        map<int,map<int,multiset<int>>>m;
        //node   vertical    level
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            root=q.front().first;
            int v=q.front().second.first;
            int l=q.front().second.second;
            q.pop();
            if(root->left!=NULL)
            {
                q.push({root->left,{v-1,l+1}});
            }
            if(root->right!=NULL)
            {
                q.push({root->right,{v+1,l+1}});
            }
            m[v][l].insert(root->val);
        }
        vector<vector<int>>ans;
        for(auto p:m)
        {
            vector<int>col;
            for(auto x:p.second)
            {
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};