class Solution {
public:
    static bool comparator(int a,int b)
    {
        return a>b;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit=0;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<difficulty.size();i++)
            pq.push({profit[i],difficulty[i]});
        sort(worker.begin(),worker.end(),comparator);
        int i=0;
        while(i<worker.size()&&!pq.empty())
        {
            auto it=pq.top();
            while(i<worker.size()&&it.second<=worker[i])
            {
                maxProfit+=it.first;
                i++;
            }
            pq.pop();
        }
        return maxProfit;
    }
};