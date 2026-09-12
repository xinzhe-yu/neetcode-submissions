class Solution {
public:

    string encode(vector<string>& strs) {
        string key = "";
        for(auto& str : strs) {
            key += to_string(str.size()) + "#" + str;
        }
        return key;
    } 

    // 5#Hello5#Hello

    vector<string> decode(string s) {
        //find # make substring
        vector<string> arr;

        int pos = 0; 
        while (pos < s.size()) {
            int delim_pos = s.find("#", pos);
            int len = stoi(s.substr(pos, delim_pos - pos));
            arr.push_back(s.substr(delim_pos + 1, len));
            pos = pos + 1 + len + (delim_pos - pos);
        }

        return arr; 
        


    }
};
