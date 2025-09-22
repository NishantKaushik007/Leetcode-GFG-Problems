class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        for(int num:nums)
        freq[num]++;
        int maxFreq=-1,count=0;
        for(int i=1;i<=100;i++)
        {
            maxFreq=max(maxFreq,freq[i]);
        }
        for(int i=1;i<=100;i++)
        {
            if(freq[i]==maxFreq)
            count+=freq[i];
        }
        return count;
    }
};