class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        for(int i=0;i<fruits.size();i++)
        {
            int unset=1;
            for(int j=0;j<baskets.size();j++)
            {
                if(baskets[j]>=fruits[i])
                {
                    baskets[j]=0;
                    unset=0;
                    break;
                }
            }
            count+=unset;
        }
        return count;
    }
};