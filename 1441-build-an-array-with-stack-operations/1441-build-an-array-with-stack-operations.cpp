class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>str;
        int range=1,ind=0;
        while(range<=n&&ind<target.size())
        {
            if(range==target[ind])
            {
                str.push_back("Push");
                ind++;
            }
            else{
                str.push_back("Push");
                str.push_back("Pop");
            }
            range++;
        }
        return str;
    }
};