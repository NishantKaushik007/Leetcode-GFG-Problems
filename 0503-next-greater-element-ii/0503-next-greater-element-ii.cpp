class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge(nums.size());
        stack<int>st;
        for(int i=(nums.size()*2)-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i%nums.size()])
            st.pop();
            if(i<nums.size())
            nge[i]=st.empty()?-1:st.top();
            st.push(nums[i%nums.size()]);
        }
        return nge;
    }
};