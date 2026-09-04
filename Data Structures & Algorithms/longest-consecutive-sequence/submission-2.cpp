class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& i : nums) {
            s.insert(i);
        }

        int longest = 0; 

        for (auto& num : s) {
            int count = 1; 
            int curr = num;
            if (!s.contains(num-1)) {
                while (s.contains(curr + 1)) {
                    count++;
                    curr++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
