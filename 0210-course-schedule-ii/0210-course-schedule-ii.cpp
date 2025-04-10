class Solution {
public:
    bool haveCycle(int node,vector<int> adj[],vector<int>& vis,vector<int>& pathVis,stack<int>& st)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(haveCycle(it,adj,vis,pathVis,st)==true)
                return true;
            }
            else if(pathVis[it])
            return true;
        }
        st.push(node);
        pathVis[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0),pathVis(numCourses,0),adj[numCourses],topo;
        stack<int>st;
        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(haveCycle(i,adj,vis,pathVis,st)==true)
                return {};
            }
        }
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};