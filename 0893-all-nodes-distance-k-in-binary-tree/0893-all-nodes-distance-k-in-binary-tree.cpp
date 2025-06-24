/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->left!=NULL)
            {
                q.push(root->left);
                parent[root->left]=root;
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
                parent[root->right]=root;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        findParent(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int count=0;
        while(!q.empty())
        {
            vector<int>v;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                root=q.front();
                q.pop();
                if(vis.find(root->left)==vis.end()&&root->left!=NULL)
                {
                    vis[root->left]=true;
                    q.push(root->left);
                }
                if(vis.find(root->right)==vis.end()&&root->right!=NULL)
                {
                    vis[root->right]=true;
                    q.push(root->right);
                }
                if(vis.find(parent[root])==vis.end()&&parent[root]!=NULL)
                {
                    vis[parent[root]]=true;
                    q.push(parent[root]);
                }
                v.push_back(root->val);
            }
            count++;
            if(count==k+1)
            {
                return v;
            }
        }
        return {};
    }
};