class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> arr(nums.size() + 1);
        vector<int> ans; 

        for (auto& n : nums) {
            mp[n]++;
        }

        for (auto& p : mp) {
            arr[p.second].push_back(p.first);
        }

        for (int i = arr.size() - 1; i > 0; i--) {
            for (auto& item : arr[i]) {
                ans.push_back(item);
                if (ans.size() == k) {
                    return ans; 
                }
            }
        }

        return ans;
    }
};
