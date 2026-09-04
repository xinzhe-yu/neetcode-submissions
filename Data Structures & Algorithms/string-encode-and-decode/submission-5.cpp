class Solution {
public:

    string encode(vector<string>& strs) {
        string key;
        for (auto& s : strs) {
            key += to_string(s.size()) + "#" + s;
            //5#Hello5#Hello5#Hello
        }
        return key;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int pos = 0;
        while (pos < s.size()) {
            int delim_index = s.find("#", pos); //index 
            int size_len = delim_index - pos;
            string size = s.substr(pos, size_len);
            int word_len = stoi(size);

            ans.push_back(s.substr(pos + 1 + size_len, word_len));
            pos += 1 + size_len + word_len;

        }
        return ans;
        
    }
};
