class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        
        for (const auto& str : strs) {
            vector<int> arr(26, 0);
            for (const char c : str) {
                arr[(int)c - 'a'] += 1;
            }

            string key;
            for (auto& i : arr) {
                key += ',' + to_string(i);
            }

            res[key].push_back(str);
   
        } 

        vector<vector<string>> ans; 
        for (const auto& p : res) {
            ans.push_back(p.second);
        }

        return ans;


    }
};
