class Solution {
public:
    bool dfs(int node,int color,vector<int>& col,vector<int> adj[])
    {
        col[node]=color;
        for(auto it:adj[node])
        {
            if(col[it]==-1)
            {
                col[it]=!color;
                if(dfs(it,!color,col,adj)==false)
                    return false;
            }
            else{
                if(col[it]==color)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1),adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[i].push_back(it);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(dfs(i,0,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};