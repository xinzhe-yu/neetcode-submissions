class Solution {
public:

    string encode(vector<string>& strs) {
        // a list ot string to string
        string input; 
        for (auto& str : strs) {
            input += to_string(str.size()) + "#" + str;
        }
        return input;
    }

    vector<string> decode(string s) {
        vector<string> ans; 


        int pos = 0; 
        while(pos < s.size()) {
            
            int delim = s.find('#', pos);
            int num_length = delim - pos; 
            int str_len = stoi(s.substr(pos, num_length));
            string str = s.substr(pos + num_length + 1, str_len);
            ans.push_back(str);
            pos = pos + num_length + str_len + 1; 

        }
      

        return ans;
    }
};
