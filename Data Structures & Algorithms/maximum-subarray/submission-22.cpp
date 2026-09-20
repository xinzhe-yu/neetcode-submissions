class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curr_window = 0; 
        int max_window = nums[0];
        
        for (auto& n : nums) {
            if (curr_window < 0) {
                curr_window = 0; 
            }
            curr_window += n; 
            max_window = max(max_window, curr_window);
        }
        return max_window; 
    }
};
