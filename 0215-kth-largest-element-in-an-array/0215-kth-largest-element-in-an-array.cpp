class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int num=-1;
        for(int i=0;i<k;i++)
        {
            num=pq.top();
            pq.pop();
        }
        return num;
    }
};