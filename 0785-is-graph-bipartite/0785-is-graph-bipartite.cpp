class Solution {
public:
    bool bfs(int node,vector<int>& col,vector<int> adj[])
    {
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(col[it]==-1)
                {
                    q.push(it);
                    col[it]=!col[node];
                }
                else{
                    if(col[it]==col[node])
                        return false;
                }
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
                if(bfs(i,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};