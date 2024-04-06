class Solution {
public:
    string makeGood(string s) {
        int end=0;
        for(int i=0;i<s.length();i++)
        {
            if(end>0&&abs(s[i]-s[end-1])==32)
            end--;
            else
            {
                s[end]=s[i];
                end++;
            }
        }
        return s.substr(0,end);
    }
};