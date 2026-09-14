class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> arr(nums.size(), 0 );

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                arr[0] = 1;
                continue;
            }
            arr[i] = nums[i - 1] * arr[i - 1];
        }

 

        int curr = 1; 
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                curr = 1 * nums[nums.size() - 1];
                continue;
            }
            arr[i] = curr * arr[i];
            curr = curr * nums[i];
        }

        return arr; 
    }
};
