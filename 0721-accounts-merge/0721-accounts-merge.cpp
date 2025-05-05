class DisjointSet{
    public:
    vector<int>parent,rank,size;
    DisjointSet(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i]=i;
        rank.resize(n,0);
        size.resize(n,1);
    }
    int findUParent(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int upu=findUParent(u);
        int upv=findUParent(v);
        if(upu==upv)
        return;
        if(rank[upu]<rank[upv])
        parent[upu]=upv;
        else if(rank[upv]<rank[upu])
        parent[upv]=upu;
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int upu=findUParent(u);
        int upv=findUParent(v);
        if(upu==upv)
        return;
        if(size[upu]<size[upv])
        parent[upu]=upv;
        else{
            size[upu]+=size[upv];
            parent[upv]=upu;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())
                mapMailNode[mail]=i;
                else
                ds.unionBySize(i,mapMailNode[mail]);
            }
        }
        vector<string>mergedMail[n];
        for(auto it:mapMailNode)
        {
            string mail=it.first;
            int node=ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0)
            continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i])
            temp.push_back(it);
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};