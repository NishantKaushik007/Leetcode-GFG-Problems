class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),maxProfit=0,totProfit=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        v.push_back({difficulty[i],profit[i]});
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++)
        v[i].second=max(v[i-1].second,v[i].second);
        sort(worker.begin(),worker.end());
        int j=0;
        for(int i=0;i<worker.size();i++)
        {
            while(j<n&&worker[i]>=v[j].first)
            {
                maxProfit=max(maxProfit,v[j].second);
                j++;
            }
            totProfit+=maxProfit;
        }
        return totProfit;
    }
};