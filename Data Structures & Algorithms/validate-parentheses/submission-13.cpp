class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        

        for (auto& c : s) {
            if (mp.contains(c)) { // pop or return
                if (!stk.empty() && stk.top() == mp[c]) {
                    stk.pop();
                }
                else {
                    return false;
                }
            } 
            else {
                stk.push(c);
            }
        }

        if (stk.empty()) {
            return true;
        }

        return false; 
        
    }
};
