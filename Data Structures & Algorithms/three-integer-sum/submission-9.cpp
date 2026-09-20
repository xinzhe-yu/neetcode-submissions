class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int L = i + 1;
            int R = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; 
            }

            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});

                    L++;
                    while (L < R && nums[L] == nums[L - 1]) {
                        L++;
                    }

                    R--;
                    while (L < R && nums[R] == nums[R + 1]) {
                        R--;
                    }

                } else if (sum > 0) {
                    R--;
                } else if (sum < 0) {
                    L++;
                }
            }
        }

        return ans;
    }
};
