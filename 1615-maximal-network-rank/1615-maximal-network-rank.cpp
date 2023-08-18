class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank=INT_MIN,total=0;
        unordered_map<int,unordered_set<int>>adj;
        for(auto it:roads)
        {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int iRank=adj[i].size();
                int jRank=adj[j].size();
                total=iRank+jRank;
                if(adj[i].find(j)!=adj[i].end())
                    total-=1;
                maxRank=max(maxRank,total);
            }
            total=0;
        }
        return maxRank;
    }
};