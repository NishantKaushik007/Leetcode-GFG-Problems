class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>m;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int num=arr[i],count=0;
            int x=num;
            while(num>0)
            {
                num=num&(num-1);
                count++;
            }
            m[count].push_back(x);
        }
        for(auto x:m)
        {
            vector<int>v(x.second.begin(),x.second.end());
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++)
                ans.push_back(v[i]);
        }
        return ans;
    }
};