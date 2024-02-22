class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>freq(n+1,0);
        set<int>t;
        for(int i=0;i<trust.size();i++)
        {
            freq[trust[i][1]]++;
            t.insert(trust[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==n-1&&t.find(i)==t.end())
                return i;
        }
        return -1;
    }
};