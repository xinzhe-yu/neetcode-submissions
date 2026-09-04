class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            vector<int> arr(26,0);
            for (char c : str) {
                int index = c - 'a';
                arr[index]++;
            }

            string key = " ";
            for (auto& item : arr) {
                key += ',' + item;
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
