class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0),adj[rooms.size()];
        for(int i=0;i<rooms.size();i++)
        {
            for(int it:rooms[i])
            {
                int u=i;
                int v=it;
                adj[u].push_back(v);
            }
        }
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(int i=0;i<rooms.size();i++)
        {
            if(vis[i]==0)
            return false;
        }
        return true;
    }
};