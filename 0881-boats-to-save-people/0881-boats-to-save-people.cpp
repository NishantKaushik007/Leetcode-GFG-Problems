class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int>freq(limit+1,0),v;
        for(int i=0;i<people.size();i++)
        {
            freq[people[i]]++;
        }
        for(int i=1;i<=limit;i++)
        {
            while(freq[i]!=0)
            {
                v.push_back(i);
                freq[i]--;
            }
        }
        int i=0,j=v.size()-1,boat=0;
        if(v[j]>limit)
            return -1;
        while(i<=j)
        {
            if(v[i]+v[j]<=limit)
            {
                boat++;
                i++;
                j--;
            }
            else if(v[j]<=limit)
            {
                boat++;
                j--;
            }
        }
        return boat;
    }
};