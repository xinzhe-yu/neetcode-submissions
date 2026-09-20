class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops; // forgot how to init
        stack<int> stk; 

        ops.insert("+");
        ops.insert("*");
        ops.insert("-");
        ops.insert("/");

        for (auto& t : tokens) {
            if (ops.contains(t)) {
                int second;

                if (!stk.empty()) {
                    second = stk.top(); 
                    stk.pop();
                } else {
                    continue;
                }
                
                int first;
                if (!stk.empty()) {
                    first = stk.top(); 
                    stk.pop();
                } else {
                    continue;
                }
                
                
                
                // +
                if (t == "+") {
                    stk.push(first + second);
                }
                else if (t == "*") {
                    stk.push(first * second);
                }
                else if (t == "-") {
                    stk.push(first - second);
                } 
                else if (t == "/") {
                    stk.push(first / second);
                }
            }

            else {
                stk.push(stoi(t));
            }

            
        }
        if (!stk.empty()) {
            return stk.top();
        }

        return -1;
    }
};
