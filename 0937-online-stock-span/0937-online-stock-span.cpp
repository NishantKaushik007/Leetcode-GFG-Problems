class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty()&&st.top().first<=price)
        st.pop();
        int psee=st.empty()?ind-(-1):ind-st.top().second;
        st.push({price,ind++});
        return psee;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */