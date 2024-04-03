class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        string ans="";
        while(i<s.length())
        {
            while(i<s.length()&&s[i]==' ')
                i++;
            if(i>=s.length())
                break;
            j=i+1;
            while(j<s.length()&&s[j]!=' ')
                j++;
            if(ans.size()==0)
                ans+=s.substr(i,j-i);
            else
                ans=s.substr(i,j-i)+" "+ans;
            i=j+1;
        }
        return ans;
    }
};