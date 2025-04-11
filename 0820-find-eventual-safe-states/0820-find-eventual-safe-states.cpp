class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0),adjT[graph.size()],indegree(graph.size(),0),topo;
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            for(auto it:graph[i])
            {
                int u=it;
                int v=i;
                adjT[u].push_back(v);
                indegree[v]++;
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i]&&indegree[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjT[node])
            {
                indegree[it]--;
                if(!vis[it]&&indegree[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};