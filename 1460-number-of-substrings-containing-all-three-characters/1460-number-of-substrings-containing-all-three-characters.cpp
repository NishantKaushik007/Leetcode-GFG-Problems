class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int ind[3]={-1,-1,-1};
        for(int i=0;i<s.length();i++)
        {
            ind[s[i]-'a']=i;
            if(ind[0]!=-1&&ind[1]!=-1&&ind[2]!=-1)
            count+=1+min(ind[0],min(ind[1],ind[2]));
        }
        return count;
    }
};