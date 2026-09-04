class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        
        for (auto& num : nums) {
            mp[num]++;
            //arr[mp[num]].push_back(num);
        }

        vector<vector<int>> arr(nums.size() + 1);
        for (auto& p : mp) {
            arr[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = arr.size() - 1; i >= 0; i--) {
            for (auto& num : arr[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
