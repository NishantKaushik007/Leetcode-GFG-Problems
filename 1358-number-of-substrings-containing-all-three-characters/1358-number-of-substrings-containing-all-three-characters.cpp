class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0,count=0;
        while(r<s.length())
        {
            mp[s[r]]++;
            while(mp.size()==3)
            {
                count+=s.length()-r;
                mp[s[l]]--;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};