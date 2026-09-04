class Solution {
public:

    string encode(vector<string>& strs) {
        string key = "";
        for (auto& s : strs) {
            int s_size = s.size();
            key += to_string(s_size) + "#" + s;
        }
        return key; 
    }

    vector<string> decode(string s) {
        int pos = 0;
        vector<string> ans; 

        while (pos < s.size()) {
            int delim_index = s.find("#", pos);
            string length = s.substr(pos, delim_index - pos);
            int str_len = stoi(length);

            string anss = s.substr(pos + 1 + length.size(), str_len);

            ans.push_back(anss);

            pos += length.size() + 1 + str_len;


        }
        return ans;
    }
};
