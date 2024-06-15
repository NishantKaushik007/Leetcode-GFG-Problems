class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int ptr=0;
        for(int i=0;i<k;i++)
        {
            while(ptr<n&&v[ptr].first<=w)
            {
                pq.push(v[ptr++].second);
            }
            if(pq.empty())
            {
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};