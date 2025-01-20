class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>RomToInt;
        RomToInt['I']=1;
        RomToInt['V']=5;
        RomToInt['X']=10;
        RomToInt['L']=50;
        RomToInt['C']=100;
        RomToInt['D']=500;
        RomToInt['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(RomToInt[s[i]]<RomToInt[s[i+1]])
            ans-=RomToInt[s[i]];
            else
            ans+=RomToInt[s[i]];
        }
        return ans;
    }
};