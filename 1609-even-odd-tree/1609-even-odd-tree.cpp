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
    bool isEvenOddTree(TreeNode* root) {
        int prevOdd=INT_MAX;
        int prevEven=INT_MIN;
        int level=0;
        if(root->val%2==0)
            return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            level++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL)
                {
                    if(level%2==1&&node->left->val%2==0&&node->left->val<prevOdd)
                    {
                        q.push(node->left);
                        prevOdd=node->left->val;
                    }
                    else if(level%2==0&&node->left->val%2==1&&node->left->val>prevEven)
                    {
                        q.push(node->left);
                        prevEven=node->left->val;
                    }
                    else{
                        return false;
                    }
                }
                if(node->right!=NULL)
                {
                    if(level%2==1&&node->right->val%2==0&&node->right->val<prevOdd)
                    {
                        q.push(node->right);
                        prevOdd=node->right->val;
                    }
                    else if(level%2==0&&node->right->val%2==1&&node->right->val>prevEven)
                    {
                        q.push(node->right);
                        prevEven=node->right->val;
                    }
                    else{
                        return false;
                    }
                }
            }
            prevOdd=INT_MAX;
            prevEven=INT_MIN;
        }
        return true;
    }
};