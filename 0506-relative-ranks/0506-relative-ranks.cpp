class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>v;
        vector<string>ans(score.size(),"");
        for(int i=0;i<score.size();i++)
        {
            v.push_back({score[i],i});
        }
        sort(v.begin(),v.end());
        ans[v[score.size()-1].second]="Gold Medal";
        if(score.size()>1)
        ans[v[score.size()-2].second]="Silver Medal";
        if(score.size()>2)
        ans[v[score.size()-3].second]="Bronze Medal";
        int j=4;
        for(int i=score.size()-4;i>=0;i--)
        {
            ans[v[i].second]=to_string(j);
            j++;
        }
        return ans;
    }
};