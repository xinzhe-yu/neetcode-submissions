class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size()); 
        int n = 1; 

        ans[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans[i+1] = n * nums[i];
            n = ans[i+1];
        }

        int reverse = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = ans[i] * reverse; 
            reverse = reverse * nums[i]; 
        }

        return ans;
    }
};
