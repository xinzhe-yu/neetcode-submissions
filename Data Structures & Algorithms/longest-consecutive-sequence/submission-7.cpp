class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int len = 0;
        for (auto& num : nums) {
            int cnt = 1;
            if (!set.contains(num - 1)) {
                while (set.contains(num + cnt)) {
                    cnt++;
                }
                
                len = max(cnt, len);
            }
        }

        return len; 
    }
};
