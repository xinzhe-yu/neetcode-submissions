class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

    int size = nums.size();
    vector<int> arr(size * 2,0);
    
    for (int i = 0; i < size; i++) {
        arr[i] = nums[i];
        arr[i + size] = nums[i];
    }

    
    return arr;
    
    }
};
