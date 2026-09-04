class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto& c : s) {
            if (mp.contains(c) && !stack.empty() && stack.top() == mp[c]) {
                stack.pop();
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
