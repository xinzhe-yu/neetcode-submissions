class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currsum = 0;
        int maxsum = nums[0];

        for (int& n : nums) {
            currsum = max(currsum, 0); // make sure previous sum is none negative
            currsum += n;
            maxsum = max(currsum, maxsum);
        }
        return maxsum;
    }
};
