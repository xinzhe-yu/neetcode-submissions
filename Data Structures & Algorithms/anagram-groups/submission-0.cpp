#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, int> mp;
        vector<vector<string>> ans;
        int cnt = 0; 
        for (size_t i = 0; i < strs.size(); i++) {
            // if in map append to list 
            std::string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            if (mp.contains(sorted)) {
                ans[mp[sorted]].push_back(strs[i]);
            } 

            // if not in map add to map and init list 
            else { 
                mp[sorted] = cnt;
                cnt++;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};


