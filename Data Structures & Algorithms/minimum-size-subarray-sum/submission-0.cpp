class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0; 
        int minlength = nums.size()+1;
        int window = 0;

        for (int R = 0; R < nums.size(); R++) {
            window += nums[R];
            while (window >= target) {
                minlength = min((R-L) + 1, minlength);
                window -= nums[L];
                L++;
            }
        }
        return minlength == nums.size()+1 ? 0 : minlength; 
    }
};