class Solution {
public:
    int mod=(int)1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),sum=0;
        vector<int>psee(n),nse(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //incase of repeating element like 2,2. 
            //We are considering it 1 time. So, our nse remain normal but one must be changed.
            //So, only changing logic of psee(prevSmallerEqualElement).
            //So, only remove greater elements do not remove equal elements.
            while(!st.empty()&&arr[st.top()]>arr[i])
            st.pop();
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            sum=(sum+((i-psee[i])*(nse[i]-i)*1LL*arr[i])%mod)%mod;
        }
        return (int)sum;
    }
};