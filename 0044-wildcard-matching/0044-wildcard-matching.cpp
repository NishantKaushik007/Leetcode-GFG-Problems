class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
        }
        for(int j=1;j<=m;j++)
        {
            bool flag=true;
            for(int x=1;x<=j;x++)
            {
                if(p[x-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                curr[j]=prev[j-1];
                else if(p[j-1]=='*')
                curr[j]=curr[j-1]|prev[j];
                else
                curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};