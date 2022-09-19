class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.length(),i=0,j;
        while(i<n)
        {
            while(i<n&&s[i]==' ')
                i++;
            if(i>=n)
                break;
            j=i+1;
            while(j<n&&s[j]!=' ')
                j++;
            if(ans.length()==0)
                ans=s.substr(i,j-i);
            else
                ans=s.substr(i,j-i)+" "+ans;
            i=j+1;
        }
        return ans;
    }
};