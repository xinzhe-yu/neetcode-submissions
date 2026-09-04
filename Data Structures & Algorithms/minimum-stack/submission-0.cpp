class MinStack {

private: 
    stack<int> min_stack;
    stack<int> my_stack;

// I will have two stacks
// One normal stack
// One stack always replace the highest number to the top 

public:
    MinStack() {
        
    }
    
    void push(int val) {
        my_stack.push(val);

        if (!min_stack.empty()) {

            int min_top = min_stack.top();
            
            if (val < min_top) {
                min_stack.push(val);
            } 
            else {
                min_stack.push(min_top);
            }
        } 
        else {
            min_stack.push(val);
        }
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
 