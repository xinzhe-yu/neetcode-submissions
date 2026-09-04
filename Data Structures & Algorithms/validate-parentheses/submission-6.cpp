class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ans;
        for (const char& bracket : s) {
            if (bracket == '{' || bracket == '(' || bracket == '[') {
                ans.push(bracket);
            }
            else if (bracket == '}') {
                if (!ans.empty() && ans.top() == '{') {
                    ans.pop();
                } 
                else {
                    return false;
                }
            } 
            else if (bracket == ')') {
                if (!ans.empty() && ans.top() == '(') {
                    ans.pop();
                }
                else {
                    return false;
                }
            } 
            else if (bracket == ']') {
                if (!ans.empty() && ans.top() == '[') {
                    ans.pop();
                }
                else {
                    return false;
                }
            } 
        
        }
        if (ans.empty()) {
            return true;
        } else {
            return false;
        }

    }
};
