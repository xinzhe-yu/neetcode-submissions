class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;

        while (L <= R) {
            int m = (L + R) / 2;
            if (nums[m] < target) {
                L = m + 1;
            } else if (target < nums[m]) {
                R = m - 1;
            } else if (target == nums[m]) {
                return m;
            }
        }
        return -1;
    }
};
