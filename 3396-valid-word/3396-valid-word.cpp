class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)
        return false;
        int vowel=0,consonant=0;
        for(int i=0;i<word.length();i++)
        {
            if((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z')||(word[i]>='0'&&word[i]<='9')){
                if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')
                vowel++;
                else if((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z'))
                consonant++;
            }
            else
            return false;
        }
        if(vowel>0&&consonant>0)
        return true;
        return false;
    }
};