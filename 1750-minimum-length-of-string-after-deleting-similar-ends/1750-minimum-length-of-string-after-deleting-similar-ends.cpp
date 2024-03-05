class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.length()-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                while(s[start]==s[start+1]&&start+1!=end)
                    start++;
                while(s[end]==s[end-1]&&start+1!=end)
                    end--;
                start=start+1;
                end=end-1;
            }
            else{
                break;
            }
        }
        return end-start+1;
    }
};