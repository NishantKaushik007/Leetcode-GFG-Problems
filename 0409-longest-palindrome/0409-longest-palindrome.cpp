class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256]={0};
        for(int i=0;i<s.length();i++)
            freq[s[i]]++;
        int even=0,odd=0;
        bool flag=false;
        for(int i=0;i<256;i++)
        {
            if(freq[i]%2==0)
                even+=freq[i];
            else
            {
                odd+=(freq[i]-1);
                flag=true;
            }
        }
        if(flag==true)
            return even+odd+1;
        return even+odd;
    }
};