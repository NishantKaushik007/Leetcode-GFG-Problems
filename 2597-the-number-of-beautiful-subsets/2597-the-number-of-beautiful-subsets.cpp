class Solution {
public:
    void subset(int ind,vector<int>& nums,vector<int>& ds,int& count,int k)
    {
        if(ind==nums.size())
        {
            int i;
            for(i=0;i<ds.size();i++)
            {
                int j;
                for(j=i+1;j<ds.size();j++)
                {
                    if(abs(ds[i]-ds[j])==k)
                        break;
                }
                if(j<ds.size())
                    break;
            }
            if(i==ds.size()&&ds.size()>0)
                count++;
            return;
        }
        ds.push_back(nums[ind]);
        subset(ind+1,nums,ds,count,k);
        ds.pop_back();
        subset(ind+1,nums,ds,count,k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>ds;
        int count=0;
        subset(0,nums,ds,count,k);
        return count;
    }
};