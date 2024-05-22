class Solution {
public:
    bool isPalindrome(string& s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void part(int ind,string& s,vector<string>& str,vector<vector<string>>& ans)
    {
        if(ind==s.size())
        {
            ans.push_back(str);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(s,ind,i))
            {
                str.push_back(s.substr(ind,i-ind+1));
                part(i+1,s,str,ans);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>str;
        part(0,s,str,ans);
        return ans;
    }
};