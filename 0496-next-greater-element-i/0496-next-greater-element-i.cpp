class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
        mp[nums2[i]]=i;
        vector<int>nge(nums2.size()),ans(nums1.size());
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums2[i])
            st.pop();
            nge[i]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=nge[mp[nums1[i]]];
        }
        return ans;
    }
};