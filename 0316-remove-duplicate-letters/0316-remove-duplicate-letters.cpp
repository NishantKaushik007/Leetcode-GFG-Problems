class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res="";
        int n=s.length();
        int lastIndex[26]={0};
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            lastIndex[ch-'a']=i;
        }
        bool vis[26]={false};
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int ind=ch-'a';
            if(vis[ind]==true)
                continue;
            while(res.length()>0&&res.back()>ch&&lastIndex[res.back()-'a']>i)
            {
                vis[res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(ch);
            vis[ind]=true;
        }
        return res;
    }
};