class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0,maxLen=0,r;
        deque<int>maxDeq,minDeq;
        for(r=0;r<nums.size();r++)
        {
            while(!maxDeq.empty()&&maxDeq.back()<nums[r])
                maxDeq.pop_back();
            maxDeq.push_back(nums[r]);
            while(!minDeq.empty()&&minDeq.back()>nums[r])
                minDeq.pop_back();
            minDeq.push_back(nums[r]);
            while(maxDeq.front()-minDeq.front()>limit)
            {
                if(maxDeq.front()==nums[l])
                    maxDeq.pop_front();
                if(minDeq.front()==nums[l])
                    minDeq.pop_front();
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};