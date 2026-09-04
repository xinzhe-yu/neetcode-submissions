class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops;
        ops.insert("+");
        ops.insert("-");
        ops.insert("*");
        ops.insert("/");

        stack<int> stk;

        for (auto& t : tokens) {
            if (ops.contains(t)) {
                int val2 = (stk.top()); 
                stk.pop();
                int val1 = (stk.top()); 
                stk.pop();

                if (t == "+") {
                    stk.push(val1+val2);
                }
                else if (t == "-") {
                    stk.push(val1-val2);
                }
                else if (t == "*") {
                    stk.push(val1*val2);
                }
                else if (t == "/") {
                    stk.push(val1/val2);
                }
            }
            else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
