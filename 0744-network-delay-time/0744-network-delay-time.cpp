class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int neighbour=it.first;
                int ncost=it.second;
                if(dist[neighbour]>cost+ncost)
                {
                    dist[neighbour]=cost+ncost;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
            return -1;
            else{
                maxi=max(maxi,dist[i]);
            }
        }
        return maxi;
    }
};