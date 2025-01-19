class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        string ans="";
        while(l<s.length())
        {
            while(l<s.length()&&s[l]==' ')
            l++;
            if(l>=s.length())
            break;
            r=l+1;
            while(r<s.length()&&s[r]!=' ')
            r++;
            string str=s.substr(l,r-l);
            if(ans.length()==0)
            ans=str;
            else
            ans=str+" "+ans;
            l=r+1;
        }
        return ans;
    }
};