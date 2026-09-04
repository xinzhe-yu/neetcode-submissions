class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        vector<int> ans; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i; 
        }
        for (int i = 0; i < n; i++) {
            int temp = target - nums[i];
    
            if (mp.count(temp)  && i != mp[temp]) {
                if (i < mp[temp]) {
                    ans.push_back(i);
                    ans.push_back(mp[temp]);
                } 
                else {
                    ans.push_back(mp[temp]);
                    ans.push_back(i);
                }
                
                return ans;
            }
        }
        

    }
};
