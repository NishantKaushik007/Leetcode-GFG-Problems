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
    TreeNode* findParent(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        TreeNode* src=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->val==start)
            src=root;
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
        return src;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>vis;
        TreeNode* src=findParent(root,start,parent);
        queue<TreeNode*>q;
        q.push(src);
        vis[src]=true;
        int time=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                if(root->left!=NULL&&!vis[root->left])
                {
                    q.push(root->left);
                    vis[root->left]=true;
                }
                if(root->right!=NULL&&!vis[root->right])
                {
                    q.push(root->right);
                    vis[root->right]=true;
                }
                if(parent[root]!=NULL&&!vis[parent[root]])
                {
                    q.push(parent[root]);
                    vis[parent[root]]=true;
                }
            }
            time++;
        }
        return time-1;
    }
};