class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        output[0] = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            output[i] = nums[i-1] * output[i-1];
        }

        for (auto& i : output) {
            cout << i << "\n";
        }
        
        int suff = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i == nums.size()) {
                suff = 1; 
                output[i] *= suff; 
                continue; 
            }
            suff = suff * nums[i+1];
            output[i] = output[i] * suff; 
            
        }
        return output;
    }
};
