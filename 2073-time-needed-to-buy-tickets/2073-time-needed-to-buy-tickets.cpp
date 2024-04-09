class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0,count=0;
        while(true)
        {
            i=i%tickets.size();
            if(tickets[i]!=0)
            {
                tickets[i]--;
                count++;
            }
            if(i==k&&tickets[i]==0)
                return count;
            i++;
        }
        return count;
    }
};