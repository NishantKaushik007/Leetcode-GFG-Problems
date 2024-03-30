class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        m[nums2[nums2.size()-1]]=-1;
        int j;
        for(int i=nums2.size()-2;i>=0;i--)
        {
            for(j=i+1;j<nums2.size();j++)
            {
                if(nums2[i]<nums2[j])
                {
                    m[nums2[i]]=nums2[j];
                    break;
                }
            }
            if(j==nums2.size())
             m[nums2[i]]=-1;   
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};