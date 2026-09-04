class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int L = 0;
        int sum = 0;
        int maxa = INT_MIN;

        for (int R = 0; R < nums.size(); R++) {
            if (sum < 0) {
                L = R;
                sum = 0;
            }
            sum += nums[R];
            maxa = max(maxa, sum);

        }
        
        return maxa;
        return -1;
    }

};