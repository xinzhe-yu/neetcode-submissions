class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;

        int cursum = 0;
        int len = nums.size()+1; 

        for (int R = 0; R < nums.size(); R++) {
            cursum += nums[R];

            while (cursum >= target) {
                len = min(R-L+1, len);
                cursum -= nums[L];
                L++;
            }

        }

        if (len == nums.size()+1) {
            return 0;
        }

        return len; 
    }
};