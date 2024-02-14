class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int k= words.size();
        for(int i=0;i<k;i++)
        {
            string chk=words[i];
            int p= words[i].length();
            int j;
            for(j=0; j<p/2;j++)
            {
                if(chk[j]!=chk[p-(j+1)])
                {
                    break;
                }
            }
            if(j==p/2)
            {
                return chk;
            }
        }
     
         return "";
    }
};