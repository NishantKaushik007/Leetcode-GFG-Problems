class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        int maxi=INT_MIN,ans=0;
        for(int num:nums)
        {
            freq[num]++;
        }
        for(int i=0;i<101;i++)
        {
            if(freq[i]>maxi)
                maxi=freq[i];
        }
        for(int i=0;i<101;i++)
        {
            if(freq[i]==maxi)
                ans+=freq[i];
        }
        return ans;
    }
};