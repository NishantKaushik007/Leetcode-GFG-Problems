class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int satisfied=0,i=0,j=0;
        while(i<s.size()&&j<g.size())
        {
            if(s[i]>=g[j])
            {
                i++;
                j++;
                satisfied++;
            }
            else
            i++;
            
        }
        return satisfied;
    }
};