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
        for(int i=0;i<worker.size();i++)
        {
            int target=worker[i],low=0,high=v.size()-1,profit=0;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(v[mid].first<=target)
                {
                    profit=max(profit,v[mid].second);
                    low=mid+1;
                }
                else
                high=mid-1;
            }
            maxProfit+=profit;
        }
        return maxProfit;
    }
};