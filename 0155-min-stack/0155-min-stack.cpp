class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        mini=1e9;
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else{
            if(val>mini)
            st.push(val);
            else{
                st.push(2LL*val-mini);
                mini=val;
            } 
        }
    }
    
    void pop() {
        if(st.empty())
        return;
        else if(st.top()<mini)
        mini=2LL*mini-st.top();
        st.pop();
    }
    
    int top() {
        if(st.empty())
        return -1;
        else if(st.top()>mini)
        return (int)st.top();
        else
        return mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */