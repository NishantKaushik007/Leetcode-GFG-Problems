class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size()),right(height.size());
        left[0]=height[0],right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++)
        {
            left[i]=max(left[i-1],height[i]);
            right[height.size()-i-1]=max(right[height.size()-i],height[height.size()-i-1]);
        }
        int water=0;
        for(int i=1;i<height.size()-1;i++)
        {
            water+=min(left[i],right[i])-height[i];
        }
        return water;
    }
};