class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1,j=s.length()-1;
        while(i>=0)
        {
            while(i>=0&&s[i]==' ')
                i--;
            if(i<0)
                return 0;
            j=i;
            while(i>=0&&s[i]!=' ')
            {
                i--;
            }
            break;
        }
        return j-i;
    }
};