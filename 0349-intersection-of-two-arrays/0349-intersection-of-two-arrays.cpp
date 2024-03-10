class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>s1,s2;
        for(int x:nums1)
        {
            s1.insert(x);
        }
        for(int x:nums2)
        {
            s2.insert(x);
        }
        if(s1.size()<s2.size())
        {
            for(int x:s1)
            {
                if(s2.find(x)!=s2.end())
                    ans.push_back(x);
            }
        }
        else{
            for(int x:s2)
            {
                if(s1.find(x)!=s1.end())
                    ans.push_back(x);
            }
        }
        return ans;
    }
};