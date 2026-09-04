#include <unordered_set>
#include <iostream>


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (set.contains(nums[i]) == false) {
                set.insert(nums[i]);
            } 
            else {
                return true; 
            }
        }
        return false;
            
    }
};