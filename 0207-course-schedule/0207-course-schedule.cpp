class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& visPath,vector<int> adj[])
    {
        vis[node]=1;
        visPath[node]=1;
        for(int it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,visPath,adj)==false)
                    return false;
            }
            else if(visPath[it]==1)
                return false;
        }
        visPath[node]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0),visPath(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,visPath,adj)==false)
                    return false;
            }
        }
        return true;
    }
};