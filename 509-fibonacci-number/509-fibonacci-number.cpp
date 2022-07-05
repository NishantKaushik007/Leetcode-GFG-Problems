class Solution {
public:
    int fib(int n) {
        int prev=1,prev2=0,i;
        if(n==0)
        return prev2;
        for(i=2;i<=n;i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};