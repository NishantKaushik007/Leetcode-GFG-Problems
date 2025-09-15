class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(char c:brokenLetters)
        st.insert(c);
        bool flag=false;
        int l=0,r=0,count=0;
        while(r<text.length())
        {
            flag=false;
            while(r<text.length()&&text[r]!=' ')
            {
                if(st.find(text[r])!=st.end())
                flag=true;
                r++;
            }
            if(flag==false)
            count++;
            l=r+1;
            r=l;
        }
        return count;
    }
};