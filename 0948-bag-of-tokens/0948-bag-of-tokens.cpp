class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0,end=tokens.size()-1,score=0;
        while(start<=end)
        {
            if(tokens[start]>power&&score>=1&&end-start>=1)
            {
                score--;
                power+=tokens[end];
                tokens[end]=0;
                end--;
            }
            else if(tokens[start]<=power&&start<=end)
            {
                while(start<=end&&tokens[start]<=power)
                {
                    score++;
                    power-=tokens[start];
                    start++;
                }
            }
            else
                break;
        }
        return score;
    }
};