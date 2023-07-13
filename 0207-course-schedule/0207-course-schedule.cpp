class Solution {
public:
    bool isCycle(int node,vector<int>& vis,vector<int>& visPath,vector<int> adj[])
    {
        vis[node]=1;
        visPath[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(isCycle(it,vis,visPath,adj)==false)
                {
                    return false;
                }
            }
            else if(visPath[it]==1)
                return false;
        }
        visPath[node]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0),visPath(numCourses,0);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,vis,visPath,adj)==false)
                    return false;
            }
        }
        return true;
    }
};