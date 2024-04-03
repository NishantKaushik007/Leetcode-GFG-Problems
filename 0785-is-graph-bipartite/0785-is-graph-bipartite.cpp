class Solution {
public:
    bool dfs(int node,int color,vector<int>& col,vector<int> adj[])
    {
        col[node]=color;
        for(int it:adj[node])
        {
            if(col[it]==-1)
            {
                if(dfs(it,!color,col,adj)==false)
                    return false;
            }
            else{
                if(col[it]==col[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()],col(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            for(int it:graph[i])
            {
                adj[i].push_back(it);
            }
        }
        for(int i=0;i<graph.size();i++)
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