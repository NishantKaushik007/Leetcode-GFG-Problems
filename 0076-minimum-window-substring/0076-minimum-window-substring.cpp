class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,count=0,startInd=-1,minLen=1e9,n=s.length(),m=t.length();
        int mp[256]={0};
        for(int i=0;i<m;i++)
        mp[t[i]]++;
        while(r<n)
        {
            if(mp[s[r]]>0)
            count++;
            mp[s[r]]--;
            while(count==m)
            {
                if(minLen>r-l+1)
                {
                    minLen=r-l+1;
                    startInd=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                {
                    count--;
                }
                l++;
            }
            r++;
        }
        return (startInd==-1)?"":s.substr(startInd,minLen);
    }
};