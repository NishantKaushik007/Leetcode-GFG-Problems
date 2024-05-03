class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.length(),m=version2.length();
        int i=0,j=0;
        long long int num1=0,num2=0;
        while(i<n||j<m)
        {
            while(i<n&&version1[i]!='.')
            {
                num1+=(num1*10+((int)(version1[i])-48));
                i++;
            }
            while(j<m&&version2[j]!='.')
            {
                num2+=(num2*10+((int)(version2[j])-48));
                j++;
            }
            if(num1<num2)
                return -1;
            else if(num1>num2)
                return 1;
            else{
                num1=0;
                num2=0;
            }
            i++;
            j++;
        }
        return 0;
    }
};