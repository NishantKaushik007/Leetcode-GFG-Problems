class FindSumPairs {
    vector<int>vec1,vec2;
    unordered_map<int,int>mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1=nums1;
        vec2=nums2;
        for(int num:vec2)
        mp[num]++;
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index]+=val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<vec1.size();i++)
        {
            int num=vec1[i];
            if(mp.find(tot-num)!=mp.end())
            ans+=mp[tot-num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */