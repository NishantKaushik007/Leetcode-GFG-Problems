class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k)
            continue;
            for(auto it:adj[node])
            {
                int neighbour=it.first;
                int ncost=it.second;
                if(dist[neighbour]>cost+ncost)
                {
                    dist[neighbour]=cost+ncost;
                    q.push({stops+1,{neighbour,dist[neighbour]}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};