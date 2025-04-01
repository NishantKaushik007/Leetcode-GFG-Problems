class Solution {
public:
    long long maxPoints(int ind,vector<vector<int>>& questions,vector<long long>& dp)
    {
        if(ind>=questions.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        long long notTake=0+maxPoints(ind+1,questions,dp);
        long long take=questions[ind][0]+maxPoints(questions[ind][1]+ind+1,questions,dp);
        return dp[ind]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
        return maxPoints(0,questions,dp);
    }
};