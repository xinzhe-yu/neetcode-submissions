class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() * 2;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i % (n/2)];
        }

        return ans;
    }
};