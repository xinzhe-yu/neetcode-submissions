class Solution {
public:

    string encode(vector<string>& strs) {
        string ans; 
        for (auto& s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans; 

        int pos = 0; 
        while (pos < s.size()) {
            size_t delim_pos = s.find('#', pos);
            size_t num_len = delim_pos - pos; 
            size_t length = stoi(s.substr(pos, num_len));
 
            ans.push_back(s.substr(pos + 1 + num_len, length));
            pos += length + 1 + num_len;
        }
        return ans;
    }
};
