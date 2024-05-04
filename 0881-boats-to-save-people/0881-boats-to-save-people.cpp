class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,boat=0;
        if(people[j]>limit)
            return -1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                boat++;
                i++;
                j--;
            }
            else if(people[j]<=limit)
            {
                boat++;
                j--;
            }
        }
        return boat;
    }
};