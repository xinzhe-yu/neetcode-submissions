class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int windowsum = 0;
        int maxsum = nums[0];

        for (auto& num : nums) {
            windowsum = max(0, windowsum);
            windowsum += num;
            maxsum = max(maxsum, windowsum);
        }

        return maxsum;
    }
};
