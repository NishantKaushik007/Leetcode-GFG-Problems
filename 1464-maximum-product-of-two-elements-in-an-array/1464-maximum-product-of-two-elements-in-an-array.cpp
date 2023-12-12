class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q(nums.begin(),nums.end());
        int first=q.top()-1;
        q.pop();
        int second=q.top()-1;
        q.pop();
        return first*second;
    }
};