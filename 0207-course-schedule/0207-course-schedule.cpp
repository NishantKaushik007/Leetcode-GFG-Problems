class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>vis(numCourses,0),indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
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
            for(auto it:adj[node])
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
        {
            if(indegree[i]>0)
            return false;
        }
        return true;
    }
};