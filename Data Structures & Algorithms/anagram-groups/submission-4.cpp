class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            vector<int> vec(26,0);
            string key = "";
            for (auto& c : str) {
                vec[c - 'a']++;
            }
            for (auto& v : vec) {
                key += "," + to_string(v);
            }
            mp[key].push_back(str);
        }

        vector<vector<string>> ans; 
        for (auto& p : mp) {
            ans.push_back(p.second);
        }

        return ans; 
    }
};
