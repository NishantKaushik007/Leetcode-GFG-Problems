class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n,0);
        bool skip=false;
        sort(deck.begin(),deck.end());
        int i=0,j=0;
        while(i<n)
        {
            if(ans[j]==0)
            {
                if(skip==false)
                {
                    ans[j]=deck[i];
                    i++;
                }
                skip=!skip;
            }
            j=(j+1)%n;
        }
        return ans;
    }
};