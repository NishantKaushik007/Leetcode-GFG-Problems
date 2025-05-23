class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,leftMax=0,rightMax=0,water=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(leftMax>height[left])
                water+=leftMax-height[left];
                leftMax=max(leftMax,height[left]);
                left++;
            }
            else{
                if(rightMax>height[right])
                water+=rightMax-height[right];
                rightMax=max(rightMax,height[right]);
                right--;
            }
        }
        return water;
    }
};