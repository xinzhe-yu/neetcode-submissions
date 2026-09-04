class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<string> strs;
        strs.push_back(s);
        strs.push_back(t);

        unordered_map<string, int> mp;
        
        for (auto& str : strs) {
            vector<int> arr(26, 0);
            for (auto& c : str) {
                int index = c - 'a';
                arr[index]++;
            }

            string key = " ";
            for (int num : arr) {
                key += "," + to_string(num);
            }
            mp[key]++;

            if (mp[key] > 1) {
                return true;
            }
            
        }

        return false;
    }
};
