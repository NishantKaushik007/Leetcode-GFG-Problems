class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int k= words.size();
        for(int i=0;i<k;i++)
        {
            string chk=words[i];
            string rev="";
            int p= chk.length();
            for(int i=p-1;i>=0;i--)
            {
                rev=rev+chk[i];
            }
            if(chk==rev)
            {
                return rev;
            }
        }
        return "";
    }
};