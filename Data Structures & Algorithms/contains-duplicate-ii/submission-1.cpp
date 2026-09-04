class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; //num, index

        for (int i = 0; i < nums.size();  i++) {
            if (!mp.contains(nums[i])) {
                mp.insert({nums[i], i});
            } 
            else {
                int sum = abs(i - mp[nums[i]]);
                if (sum <= k) {
                    return true;
                }
                // discard old set
                mp.erase(nums[i]);
                mp.insert({nums[i], i});
            }
        }
        return false;
    }
};


// find duplicate
// check i - j <= k