class MinStack {
public:
    stack<pair<int, int>> box;
    MinStack() {
    }
    
    void push(int val) {
        if(box.empty()){
            box.push({val, val});
        }
        else{
            box.push({val, min(val, box.top().second)});
        }
    }
    
    void pop() {
        box.pop();
    }
    
    int top() {
        return box.top().first;
    }
    
    int getMin() {
        return box.top().second;
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
