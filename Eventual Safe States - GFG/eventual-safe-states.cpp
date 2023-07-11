//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isCycle(int node,vector<int>& vis,vector<int>& visPath,vector<int> adj[],vector<int>& check)
    {
        vis[node]=1;
        visPath[node]=1;
        check[node]=0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(isCycle(it,vis,visPath,adj,check)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(visPath[it]==1)
            {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        visPath[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0),visPath(V,0),check(V,0),safeNodes;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                isCycle(i,vis,visPath,adj,check);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends