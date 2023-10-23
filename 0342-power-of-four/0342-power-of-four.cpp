class Solution {
public:
    bool powOfFour(int ind,int n)
    {
        if(pow(4,ind)>n)
            return false;
        if(pow(4,ind)==n)
            return true;
        return powOfFour(ind+1,n);
    }
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        return powOfFour(1,n);
    }
};