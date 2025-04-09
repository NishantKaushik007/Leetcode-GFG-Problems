class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<int>prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++)
            {
                int match=0;
                if(text1[i-1]==text2[j-1])
                match=1+prev[j-1];
                int notMatch=max(prev[j],curr[j-1]);
                curr[j]=max(match,notMatch);
            }
            prev=curr;
        }
        return prev[m];
    }
};