class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis)==true)
                return true;
            }
            else if(pathVis[it])
            return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>vis(numCourses,0),pathVis(numCourses,0);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathVis)==true)
                return false;
            }
        }
        return true;
    }
};