class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int j=0,n=happiness.size()-1;
        long long sum=0;
        sort(happiness.begin(),happiness.end());
        while(k--)
        {
            if(happiness[n]-j>0)
            {
                sum+=happiness[n]-j;
                n--;
                j++;
            }
            else{
                break;
            }
        }
        return sum;
    }
};