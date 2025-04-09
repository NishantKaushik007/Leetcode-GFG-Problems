class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=m;i++)
        prev[i]=i;
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                int match=1e9;
                if(word1[i-1]==word2[j-1])
                match=prev[j-1];
                int notMatch=1+min(prev[j-1],min(prev[j],curr[j-1]));
                curr[j]=min(match,notMatch);
            }
            prev=curr;
        }
        return prev[m];
    }
};