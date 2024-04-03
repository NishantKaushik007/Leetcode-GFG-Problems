class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0),adj[numCourses],indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int it:adj[node])
            {
                if(!vis[it])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        for(int i=0;i<numCourses;i++)
            if(!vis[i])
                return false;
        return true;
    }
};