class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        int num=n;
        while(num)
        {
            count+=1;
            num=num&(num-1);
        }
        return count;
    }
};