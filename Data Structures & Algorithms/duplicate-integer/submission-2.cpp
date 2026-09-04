class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (auto& num : nums) {
            if (!s.contains(num)) {
                s.insert(num);
            } else {
                return true; 
            }
            
        }

        return false;


    }
};