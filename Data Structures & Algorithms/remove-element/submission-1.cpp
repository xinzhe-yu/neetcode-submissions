class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();

        for (size_t i = size; i-- > 0; ) {
            if (nums[i] == val){
                nums[i] = nums.back();
                nums.pop_back();
            }
        }

        
        return (int)nums.size();






    }
};