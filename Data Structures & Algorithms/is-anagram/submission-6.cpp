class Solution {
public:
    bool isAnagram(string s, string t) {
        //bit apporach 
        vector<string> strs;
        strs.push_back(t);
        strs.push_back(s);

        unordered_map<string, int> mp;

        for (auto& str : strs) {
            vector<int> key(26, 0);
            for (char c : str) {
                int i = c - 'a';
                key[i]++;
            }

            string keys = " ";
            for (int& n : key) {
                keys += "," + to_string(n);
            }

            if (!mp.contains(keys)) {
                mp[keys]++;
            }
            else {
                return true;
            }
            

        } 

        return false; 

    }
};
