class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int x=0,y=0,exor=0;
        for(int i=1;i<=nums.size();i++)
        {
            exor^=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            exor^=nums[i];
        }
        int lastSetBit=exor&~(exor-1);
        for(int i=0;i<nums.size();i++)
        {
            if(lastSetBit&nums[i])
                x^=nums[i];
            else
                y^=nums[i];
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(lastSetBit&i)
                x^=i;
            else
                y^=i;
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==x)
                count++;
        }
        if(count!=0)
        {
            ans.push_back(x);
            ans.push_back(y);
        }
        else{
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
    }
};