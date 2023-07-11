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
    void linkingParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL)
            {
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        linkingParent(root,parent_track);
        vector<int>ans;
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int currLvl=0;
        while(!q.empty())
        {
            int size=q.size();
            if(currLvl++==k)
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL&&vis[curr->left]==false)
                {
                    vis[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right!=NULL&&vis[curr->right]==false)
                {
                    vis[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent_track[curr]!=NULL&&vis[parent_track[curr]]==false)
                {
                    vis[parent_track[curr]]=true;
                    q.push(parent_track[curr]);
                }
            }
        }
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};