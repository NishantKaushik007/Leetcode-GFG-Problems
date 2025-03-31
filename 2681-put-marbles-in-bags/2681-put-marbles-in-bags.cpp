class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>pairSum;
        for(int i=0;i<weights.size()-1;i++)
        pairSum.push_back(weights[i]+weights[i+1]);
        sort(pairSum.begin(),pairSum.end());
        long long maxi=0,mini=0;
        for(int i=0;i<k-1;i++)
        {
            maxi+=pairSum[pairSum.size()-i-1];
            mini+=pairSum[i];
        }
        return maxi-mini;
    }
};