class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int j=0;
        long long sum=0;
        priority_queue<int>pq;
        for(int x:happiness)
            pq.push(x);
        while(k--)
        {
            if(pq.top()-j>0)
            {
                sum+=pq.top()-j;
                pq.pop();
                j++;
            }
            else{
                break;
            }
        }
        return sum;
    }
};