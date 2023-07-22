class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathVis,vector<int> adj[],stack<int>& s)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathVis,adj,s)==true)
                    return true;
            }
            else if(pathVis[it]==1)
                return true;
        }
        s.push(node);
        pathVis[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses],vis(numCourses,0),pathVis(numCourses,0),topo;
        stack<int>s;
        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathVis,adj,s)==true)
                    return {};
            }
        }
        while(!s.empty())
        {
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }
};