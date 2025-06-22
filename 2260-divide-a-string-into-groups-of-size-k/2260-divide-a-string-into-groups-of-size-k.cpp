class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length(),i;
        vector<string>ans;
        for(i=0;i<n;i+=k)
        {
            ans.push_back(s.substr(i,k));
        }
        ans.back() += string(k - ans.back().length(), fill);
        return ans;
    }
};