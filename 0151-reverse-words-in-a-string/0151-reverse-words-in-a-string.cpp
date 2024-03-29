class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0,j=0;
        while(i<s.length())
        {
            while(i<s.length()&&s[i]==' ')
                i++;
            if(i>=s.length())
                break;
            j=i+1;
            while(j<s.length()&&s[j]!=' ')
                j++;
            if(ans.length()==0)
                ans+=s.substr(i,j-i);
            else
            ans=s.substr(i,j-i)+" "+ans;
            i=j+1;
        }
        return ans;
    }
};