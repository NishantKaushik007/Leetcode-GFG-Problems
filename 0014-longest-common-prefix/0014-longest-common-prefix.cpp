class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen=strs[0].length();
        for(int i=1;i<strs.size();i++)
        {
            if(strs[i].length()<minLen)
            minLen=strs[i].length();
        }
        int i=0,j;
        while(i<minLen)
        {
            char c=strs[0][i];
            for(j=1;j<strs.size();j++)
            {
                if(c!=strs[j][i])
                {
                    break;
                }
            }
            if(j!=strs.size())
                break;
            i++;
        }
        return strs[0].substr(0,i);
    }
};