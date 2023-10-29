class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs=0,trails=minutesToTest/minutesToDie;
        while(pow(trails+1,pigs)<buckets)
        {
            pigs++;
        }
        return pigs;
    }
};