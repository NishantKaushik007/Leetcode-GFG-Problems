class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastSeen(3,-1);
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1)
            count+=min(lastSeen[0],min(lastSeen[1],lastSeen[2]))+1;
        }
        return count;
    }
};