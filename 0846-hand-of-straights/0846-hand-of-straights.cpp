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
            int num=m.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(m[num+i]==0)
                    return false;
                m[num+i]--;
                if(m[num+i]<1)
                    m.erase(num+i);
            }
        }
        return true;
    }
};