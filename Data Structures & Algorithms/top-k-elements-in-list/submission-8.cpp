class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp; //num, occurrence 
        vector<vector<int>> vec(nums.size() + 1); // index = occurrence 
        vector<int> ans; 

        for (auto& num : nums) {
            mp[num]++;
        }

        for (auto& p : mp) {
            vec[p.second].push_back(p.first);  
        }

        for (int i = vec.size() - 1; i >= 0; i--) {
            for (auto& occ : vec[i]) {
                ans.push_back(occ);
                if (k == ans.size()) {
                    return ans; 
                }
            } 
        }

        return ans; 
    }
};
