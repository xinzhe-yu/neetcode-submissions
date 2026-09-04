class MyStack {

private: 
    std::queue<int> main;
    std::queue<int> temp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);
        int n = main.size();
        for (int i = 0 ; i < n; i++) {
            temp.push(main.front());
            main.pop();
        }
        std::swap(main, temp);
    }
    
    int pop() {
        int a = main.front();
        main.pop(); 
        return a;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        if (main.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */