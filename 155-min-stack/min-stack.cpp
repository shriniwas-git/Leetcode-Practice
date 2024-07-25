class MinStack {
public:
    pair<int,int> arr[100000];
    int tp;
    MinStack() {
        tp = -1;
    }
    
    void push(int val) {
        if(tp==-1){
            arr[++tp] = {val,val};
        }else{
            pair<int,int> prev = arr[tp];
            pair<int,int> cur = {val,min(val,prev.second)};
            arr[++tp] = cur;
        }
    }
    
    void pop() {
        tp--;
    }
    
    int top() {
        return arr[tp].first;
    }
    
    int getMin() {
        return arr[tp].second;
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