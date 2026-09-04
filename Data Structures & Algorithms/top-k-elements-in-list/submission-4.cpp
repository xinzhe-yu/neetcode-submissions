class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }

        vector<vector<int>> res(nums.size() + 1); 
        for (auto& p : mp) {
            res[p.second].push_back(p.first);
        }

        vector<int> ans; 
        int cnt = 0; 
        for (int i = res.size() - 1; i > 0; i--) {
            for (auto& k1 : res[i]) {
                ans.push_back(k1);
                if (ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
     }
};
