class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        vector<int> ans;
        for (auto& num : nums) {
            if (!mp.contains(num)) {
                mp[num] = 1;
            } else { // already in hash map 
                mp[num] += 1;
            }
        }

        // iterate map, find largest value, append key, remove key 
        for (int i = 0; i < k; ++i) {
            auto key = 0;
            auto max = 0;
            for (auto& p : mp) {
                if (p.second > max) {
                    max = p.second;
                    key = p.first;
                }
            }

            ans.push_back(key);
            mp.erase(key);
        }
      
        
        return ans;
    }
};
