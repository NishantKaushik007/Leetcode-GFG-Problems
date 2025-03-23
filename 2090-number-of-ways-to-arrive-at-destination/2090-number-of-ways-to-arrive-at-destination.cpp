class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=(int)(1e9+7);
        vector<pair<int,int>>adj[n];
        vector<long long>dist(n,LONG_MAX),ways(n,0);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            long long node=pq.top().second;
            long long time=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                long long adjNode=it.first;
                long long t=it.second;
                if(time+t<dist[adjNode])
                {
                    dist[adjNode]=time+t;
                    ways[adjNode]=ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(time+t==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};