class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        int odd=INT_MIN,even=INT_MAX;
        for(char c:s)
        mp[c]++;
        for(auto it:mp)
        {
            if(it.second%2)
            odd=max(odd,it.second);
            else
            even=min(even,it.second);
        }
        return odd-even;
    }
};