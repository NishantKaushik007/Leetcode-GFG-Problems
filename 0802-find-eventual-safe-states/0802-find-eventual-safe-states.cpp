class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& pathVis,vector<int>& check)
    {
        check[node]=0;
        vis[node]=1;
        pathVis[node]=1;
        for(int it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis,check)==true)
                {
                    check[it]=0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[it]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pathVis(n,0),check(n,0),ans;
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[i].push_back(it);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,pathVis,check);
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
              ans.push_back(i);  
        }
        return ans;
    }
};