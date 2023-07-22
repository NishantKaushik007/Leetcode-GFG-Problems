class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses],indegree(numCourses,0),ans;
        queue<int>q;
        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};