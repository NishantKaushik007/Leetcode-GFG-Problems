class Solution {
private:
    int timer=0; 
public:
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,int toi[],int low[],vector<vector<int>>& bridges)
    {
        vis[node]=1;
        toi[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
            continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,toi,low,bridges);
                low[node]=min(low[it],low[node]);
                if(low[it]>toi[node])
                bridges.push_back({it,node});
            }
            else{
                low[node]=min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n],vis(n,0);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int toi[n],low[n];
        vector<vector<int>>bridges;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            dfs(i,-1,adj,vis,toi,low,bridges);
        }
        return bridges;
    }
};