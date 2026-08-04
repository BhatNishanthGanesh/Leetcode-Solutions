class MinStack {
    stack<int>st,mnst;
public:
    MinStack() {
        
    }
    
    void push(int value) {
       if(mnst.empty() || value<=mnst.top()) mnst.push(value);
        st.push(value);
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()==mnst.top()) mnst.pop();
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return 0;
    }
    
    int getMin() {
        return mnst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */