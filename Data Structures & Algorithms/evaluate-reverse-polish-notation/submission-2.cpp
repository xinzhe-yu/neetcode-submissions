class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("*");
        op.insert("/");


        stack<string> stk; 

        for (auto& t : tokens) {
            if (op.contains(t)) {
                int b = stoi(stk.top()); stk.pop();
                int a = stoi(stk.top()); stk.pop();
                int output;
                if (t == "/") {
                    output = a/b;
                } 
                else if (t == "*") {
                    output = a*b;
                }
                else if (t == "+") {
                    output = a+b;
                } 
                else if (t == "-") {
                    output = a-b;
                }

                stk.push(to_string(output));
            }
            else {
                stk.push(t);
            }
        }

        return stoi(stk.top());
    }
};
