class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set st(nums.begin(), nums.end());

        int ans = 0;
        // identify first item
        for (auto& num : nums) {
            int tmp = 1;
            if (!st.contains(num-1)) { //first occurance 
                while(st.contains(num + 1)) {
                    tmp++;
                    num++;
                }
                ans = max(ans, tmp);

            }
        }
        return ans;
    }
};
