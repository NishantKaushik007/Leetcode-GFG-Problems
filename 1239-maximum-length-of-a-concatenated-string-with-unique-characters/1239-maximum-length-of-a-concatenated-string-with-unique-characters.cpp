class Solution {
public:
    bool hasDuplicate(string &s1,string &s2)
    {
        int arr[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            if(arr[s1[i]-'a']>0)
                return true;
            arr[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++)
        {
            if(arr[s2[i]-'a']>0)
                return true;
        }
        return false;
    }
    int solve(int ind,vector<string>& arr,string temp,int n)
    {
        if(ind>=n)
            return temp.length();
        int include=0;
        int exclude=0;
        if(hasDuplicate(arr[ind],temp))
        {
            exclude=solve(ind+1,arr,temp,n);
        }
        else{
            exclude=solve(ind+1,arr,temp,n);
            include=solve(ind+1,arr,temp+arr[ind],n);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size(),i=0;
        return solve(i,arr,temp,n);
    }
};