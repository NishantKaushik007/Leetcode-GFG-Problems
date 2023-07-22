class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0),adj[n],ans;
        for(auto it:edges)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
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
                        q.push(it);
                }
            }
        }
        if(n==1)
            ans.push_back(0);
        return ans;
    }
};