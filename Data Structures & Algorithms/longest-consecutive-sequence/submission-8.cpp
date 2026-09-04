class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set = {nums.begin(), nums.end()};

        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            // make sure its the beginning of the sequence
            if (!set.contains(nums[i] - 1)) {
                // check consecutive
                int count = 1;
                int num = nums[i];
                while (set.contains(num + 1)) {
                    num++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest; 
    }
};
