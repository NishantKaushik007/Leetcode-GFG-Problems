class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0),adj[n],ans;
        if(n==1)
        ans.push_back(0);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
                indegree[i]--;
            }
        }
        while(!q.empty())
        {
            int size=q.size();
            ans.clear();
            for(int i=0;i<size;i++)
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==1)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};