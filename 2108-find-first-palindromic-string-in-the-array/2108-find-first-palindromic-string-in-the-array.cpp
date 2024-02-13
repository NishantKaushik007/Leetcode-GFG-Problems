class Solution {
public:
    bool isPalindrome(string &str,int start,int end)
    {
        if(start>=end)
            return true;
        if(str[start]==str[end])
           return isPalindrome(str,start+1,end-1);
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        string s="";
        for(int i=0;i<words.size();i++)
        {
            if(isPalindrome(words[i],0,words[i].length()-1))
            {
                s+=words[i];
                break;
            }
        }
        return s;
    }
};