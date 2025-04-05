class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ahead(nums.size()+1,0);
        for(int ind=nums.size()-1;ind>=0;ind--)
        {
            vector<int>curr(nums.size()+1,0);
            for(int prev=nums.size()-1;prev>=-1;prev--)
            {
                int take=0;
                if(prev==-1||nums[ind]>nums[prev])
                take=1+ahead[ind+1];
                int notTake=ahead[prev+1];
                curr[prev+1]=max(take,notTake);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};