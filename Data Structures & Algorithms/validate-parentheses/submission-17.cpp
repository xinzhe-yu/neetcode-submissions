class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> stack;

        for (auto& c : s) {
            if (mp.contains(c) && !stack.empty()) {
                if (mp[c] == stack.top()) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
            
        }

        if (stack.empty()) {
            return true;
        }
        return false; 
    }
};
