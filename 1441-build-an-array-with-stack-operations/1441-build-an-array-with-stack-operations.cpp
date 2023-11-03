class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>s;
        vector<string>str;
        int range=1,ind=0;
        while(range<=n&&ind<target.size())
        {
            if(range==target[ind])
            {
                s.push(range);
                str.push_back("Push");
                ind++;
            }
            else{
                s.push(range);
                str.push_back("Push");
                s.pop();
                str.push_back("Pop");
            }
            range++;
        }
        return str;
    }
};