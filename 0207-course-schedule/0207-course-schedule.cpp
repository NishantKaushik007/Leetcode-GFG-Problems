class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses],indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
            return false;
        }
        return true;
    }
};