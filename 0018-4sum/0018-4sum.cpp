class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<nums.size();j++){
                if(j!=i+1&&nums[j]==nums[j-1])
                continue;
                int l=j+1,h=nums.size()-1;
                while(l<h){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[l];
                    sum+=nums[h];
                    vector<int>v(4);
                    if(sum==target){
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[l];
                        v[3]=nums[h];
                        ans.push_back(v);
                        l++;
                        h--;
                        while(l<h&&nums[l]==nums[l-1])
                        l++;
                        while(l<h&&nums[h]==nums[h+1])
                        h--;
                    }
                    else if(sum>target)
                    h--;
                    else
                    l++;
                }
            }
        }
        return ans;
    }
};