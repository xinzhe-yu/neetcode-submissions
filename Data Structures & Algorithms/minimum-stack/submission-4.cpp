class MinStack {
private: 
    stack<int> min;
    stack<int> stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if (min.empty() || (!min.empty() && val <= min.top())) {
            min.push(val);
        }
    }
    
    // stack: -2 -2
    //   min: -2
    void pop() {
        
        if (!stack.empty() && !min.empty() && stack.top() == min.top()) {
            stack.pop();
            min.pop();
        }
        else if (!stack.empty()) {
            stack.pop();
        }
    }
    
    int top() {
        if (!stack.empty()) {
            return stack.top();
        }
        return -1;
    }
    
    int getMin() {
        if (!min.empty()) {
            return min.top();
        }
        return -1;
    }

};
