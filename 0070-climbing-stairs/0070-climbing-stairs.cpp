class Solution {
public:
    int climbStairs(int n) {
        int prev2=1,prev=1;
        int i;
        for(i=2;i<=n;i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};