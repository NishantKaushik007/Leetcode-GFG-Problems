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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges=0,components=0;
        DisjointSet ds(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v))
            extraEdges++;
            ds.unionBySize(u,v);
        }
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            components++;
        }
        if(extraEdges>=components-1)
        return components-1;
        return -1;
    }
};