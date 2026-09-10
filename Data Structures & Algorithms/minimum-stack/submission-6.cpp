class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minstack;


public:
    MinStack() {
        //two stack 
        // one normal one track minstack
    }
    
    void push(int val) {
        stk.push(val);
        if (minstack.empty() || val <= minstack.top()) {
            minstack.push(val);
        }
    }
    
    void pop() {
        if (!stk.empty() && !minstack.empty() && stk.top() == minstack.top()) {
            minstack.pop();
        }
        if (!stk.empty()) {
            stk.pop();
        }
        
    }
    
    int top() {
        if (!stk.empty()) {
            return stk.top();
        }
        return -1;
    }
    
    int getMin() {
        if (!minstack.empty()) {
            return minstack.top();
        }
        return -1;
    }
};
