class MinStack {

private: 
    stack<int> main;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);

        if (min.empty() || (val <= min.top() && !min.empty())) {
            min.push(val);
        }
    }
    
    void pop() {
        if (!main.empty()) {
            if (main.top() == min.top()) {
                main.pop();
                min.pop();
            }
            else {
                main.pop();
            }
        }
    }
    
    int top() {
        if (!main.empty()) {
            return main.top();
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
