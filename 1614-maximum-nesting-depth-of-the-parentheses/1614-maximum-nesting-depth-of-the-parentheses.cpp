class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
                if(st.size()>maxi)
                    maxi=st.size();
            }
            else if(s[i]==')')
                st.pop();
        }
        return maxi;
    }
};