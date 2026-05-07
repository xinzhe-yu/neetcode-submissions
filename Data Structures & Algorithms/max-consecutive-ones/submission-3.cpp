static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                temp++;
            } 
            // IF zero
            else {
                //compare
                if(temp > count) { 
                    count = temp;
                }
                temp = 0;
            }
        }
        // check last time at the end
        if(temp > count) { 
            count = temp;
        }
        temp = 0;

        return count;
    }
};