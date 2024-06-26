class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,res=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
            rem=rem+k;
            if(mp.find(rem)!=mp.end())
            res+=mp[rem];
            mp[rem]++;
        }
        return res;
    }
};