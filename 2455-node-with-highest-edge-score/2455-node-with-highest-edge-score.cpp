class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int ans=-1;
        long maxi=LONG_MIN;
        vector<long>score(edges.size(),0);
        for(int i=0;i<edges.size();i++)
        {
            int u=i;
            int v=edges[i];
            score[v]+=u;
            maxi=max(maxi,score[v]);
        }
        for(int i=0;i<edges.size();i++)
        {
            if(score[i]==maxi)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};