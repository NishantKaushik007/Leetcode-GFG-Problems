//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  int timer=1;
  void dfs(int node,int parent,vector<int>& tin,vector<int>& low,vector<int>& vis,vector<int> adj[],vector<int>& mark)
  {
      vis[node]=1;
      tin[node]=low[node]=timer;
      timer++;
      int child=0;
      for(auto it:adj[node])
      {
          if(it==parent)
              continue;
          if(!vis[it])
          {
              dfs(it,node,tin,low,vis,adj,mark);
              low[node]=min(low[node],low[it]);
              if(low[it]>=tin[node]&&parent!=-1)
              mark[node]=1;
              child++;
          }
          else{
              low[node]=min(low[node],tin[it]);
          }
      }
      if(child>1&&parent==-1)
      mark[node]=1;
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>tin(V,0),low(V,0),vis(V,0),mark(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,tin,low,vis,adj,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(mark[i]==1)
            ans.push_back(i);
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends