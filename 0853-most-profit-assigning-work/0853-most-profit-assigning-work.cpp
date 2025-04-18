class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit=0;
        vector<pair<int,int>>v;
        for(int i=0;i<difficulty.size();i++)
        v.push_back({difficulty[i],profit[i]});
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        v[i].second=max(v[i-1].second,v[i].second);
        sort(worker.begin(),worker.end());
        int j=0,mprofit=0;
        for(int i=0;i<worker.size();i++)
        {
            while(worker[i]>=v[j].first&&j<v.size())
            {
                mprofit=max(mprofit,v[j].second);
                j++;
            }
            maxProfit+=mprofit;
        }
        return maxProfit;
    }
};