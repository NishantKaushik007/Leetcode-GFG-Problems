class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        map<int,int>m;
        for(int x:hand)
            m[x]++;
        while(!m.empty())
        {
            int num=m.begin()->first,n=groupSize;
            while(n!=0&&m.find(num)!=m.end())
            {
                m[num]--;
                if(m[num]<1)
                    m.erase(num);
                num++;
                n--;
            }
            if(n!=0)
                return false;
        }
        return true;
    }
};