class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int l=0,r=0;
        while(l<s.length())
        {
            while(l<s.length()&&s[l]==' ')
                l++;
            if(l>=s.length())
                break;
            r=l+1;
            while(r<s.length()&&s[r]!=' ')
                r++;
            if(ans.length()==0)
                ans+=s.substr(l,r-l);
            else
                ans=s.substr(l,r-l)+" "+ans;
            l=r+1;
        }
        return ans;
    }
};