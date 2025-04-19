class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<int>st;
        for(int i=0;i<num.length();i++)
        {
            while(!st.empty()&&k>0&&st.top()>num[i]-'0')
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k--)
        st.pop();
        while(!st.empty())
        {
            ans+=st.top()+'0';
            st.pop();
        }
        for(int i=ans.length()-1;i>=0;i--)
        {
            if(ans[i]=='0')
            ans.pop_back();
            else
            break;
        }
        if(ans.size()==0)
        return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};