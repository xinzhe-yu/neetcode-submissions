class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t s = nums.size();
        vector<vector<int>> list(s);
        unordered_map<int, int> mp;
        vector<int> ans; 

        for (int& num : nums) {
            mp[num]++;
        }
        
        vector<pair<int, int>> arr; 
        for (const auto& p : mp) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
