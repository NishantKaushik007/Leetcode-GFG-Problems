class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>revAdj[graph.size()],vis(graph.size(),0),indegree(graph.size(),0),topo;
        for(int i=0;i<graph.size();i++)
        {
            for(auto it:graph[i])
            {
                int u=it;
                int v=i;
                revAdj[u].push_back(v);
                indegree[v]++;
            }
        }
        queue<int>q;
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
            for(auto it:revAdj[node])
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
        sort(topo.begin(),topo.end());
        return topo;
    }
};