class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        if(q.size()>1)
        {
            int times=q.size()-1;
            while(times--)
            {
                int val=q.front();
                q.pop();
                q.push(val);
            }
        }
    }
    
    int pop() {
        if(!empty())
        {
            int val=q.front();
            q.pop();
            return val;
        }
        return -1;
    }
    
    int top() {
        if(!empty())
            return q.front();
        return -1;
    }
    
    bool empty() {
        if(q.size()==0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */