class StockSpanner {
public:
    //element,ind
    stack<pair<int,int>>st;
    int ind=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty()&&st.top().first<=price)
        st.pop();
        int ans=st.empty()?ind-(-1):ind-st.top().second;
        st.push({price,ind++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */