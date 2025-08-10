class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int original[10]={0};
        int nn=n;
        while(nn)
        {
            int lastDigit=nn%10;
            original[lastDigit]++;
            nn/=10;
        }
        for(int i=0;i<32;i++)
        {
            int freq[10]={0};
            long long num = 1LL << i;
            while(num)
            {
                int lastDigit=num%10;
                freq[lastDigit]++;
                num/=10;
            }
            int j;
            for(j=0;j<10;j++)
            {
                if(freq[j]!=original[j])
                break;
            }
            if(j==10)
            return true;
        }
        return false;
    }
};