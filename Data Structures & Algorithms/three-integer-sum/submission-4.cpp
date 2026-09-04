class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp; 
        unordered_set<int> used; 

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int R = nums.size() - 1; 
            int L = i + 1;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; 
            }
            //for (int L = i + 1; L < nums.size(); L++) {
            while (L < R) {
                int sum = nums[i] + nums[R] + nums[L];
                if (sum > 0) {
                    R--;
                }
                else if (sum < 0) {
                    L++;
                }
                else if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while (L < R && nums[L] == nums[L - 1]) {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R + 1]) {
                        R--;
                    }
                }
            }
            
           

            used.insert(nums[i]);
        }

        return ans;

    }
};
