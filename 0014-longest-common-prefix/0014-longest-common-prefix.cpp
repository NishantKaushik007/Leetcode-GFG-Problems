class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen=strs[0].length();
        for(auto s:strs)
        {
            if(minLen>s.length())
            minLen=s.length();
        }
        int i=0,j;
        while(i<minLen)
        {
            char ch=strs[0][i];
            for(j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=ch)
                    break;
            }
            if(j<strs.size())
                break;
            i++;
        }
        return strs[0].substr(0,i);
    }
};