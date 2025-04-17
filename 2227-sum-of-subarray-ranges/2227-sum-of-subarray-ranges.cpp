class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
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
            sum+=((i-psee[i])*(nse[i]-i)*1LL*arr[i]);
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        vector<int>pgee(n),nge(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //incase of repeating element like 2,2. 
            //We are considering it 1 time. So, our nge remain normal but one must be changed.
            //So, only changing logic of pgee(prevGreaterEqualElement).
            //So, only remove smaller elements do not remove equal elements.
            while(!st.empty()&&arr[st.top()]<arr[i])
            st.pop();
            pgee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]<=arr[i])
            st.pop();
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            sum+=((i-pgee[i])*(nge[i]-i)*1LL*arr[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long largestSum=sumSubarrayMaxs(nums);
        long long smallestSum=sumSubarrayMins(nums);
        return largestSum-smallestSum;
    }
};