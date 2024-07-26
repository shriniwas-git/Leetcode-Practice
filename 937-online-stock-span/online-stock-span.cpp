class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        ind = -1;

    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int val;
        if(st.empty()){
            val = ind+1;
        }else{
            val =  ind - st.top().second ;
        }
        st.push({price,ind});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */