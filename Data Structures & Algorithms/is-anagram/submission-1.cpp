class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> ans;
        for (char c : s) {
            auto [it, inserted] = ans.insert({c, 1});
            if (!inserted) {
                ans[c]++;
            } 
        }

        for (char c : t) {
            if (ans.contains(c) && ans[c] > 0) {
                ans[c]--;
            } 
            else {
                return false;
            }
        }
        if (s.size() == t.size()){
            return true;
        }
        return false;

    }
};
