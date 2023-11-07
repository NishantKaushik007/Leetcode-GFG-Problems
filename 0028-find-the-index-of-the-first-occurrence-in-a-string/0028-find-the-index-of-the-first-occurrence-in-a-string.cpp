class Solution {
public:
    int strStr(string haystack, string needle) {
        int sublen=needle.length();
        if(haystack.size()==needle.size()&&haystack==needle)
        {
            return 0;
        }
        if(haystack.size()<needle.size())
            return -1;
        for(int i=0;i<haystack.size()-sublen+1;i++)
        {
            string s=haystack.substr(i,sublen);
            if(i==haystack.size()-sublen-1)
            cout<<s<<" ";
            if(s==needle)
                return i;
        }
        return -1;
    }
};