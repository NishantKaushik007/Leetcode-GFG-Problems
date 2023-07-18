class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c=='#'&&!s1.empty())
            {
                s1.pop();
                continue;
            }
            if(c!='#')
            s1.push(c);
        }
        for(int i=0;i<t.length();i++)
        {
            char c=t[i];
            if(c=='#'&&!s2.empty())
            {
                s2.pop();
                continue;
            }
            if(c!='#')
            s2.push(c);
        }
        if(s1.size()!=s2.size())
            return false;
        while(!s1.empty()||!s2.empty())
        {
            if(s1.top()!=s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};