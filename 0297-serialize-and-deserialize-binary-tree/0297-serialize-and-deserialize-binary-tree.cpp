/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            ans.append("#,");
            else
            ans.append(to_string(curr->val)+",");
            if(curr!=NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
        return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                node->left=NULL;
            }
            else{
                TreeNode* nodeLeft=new TreeNode(stoi(str));
                node->left=nodeLeft;
                q.push(nodeLeft);
            }
            getline(s,str,',');
            if(str=="#")
            {
                node->right=NULL;
            }
            else{
                TreeNode* nodeRight=new TreeNode(stoi(str));
                node->right=nodeRight;
                q.push(nodeRight);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));