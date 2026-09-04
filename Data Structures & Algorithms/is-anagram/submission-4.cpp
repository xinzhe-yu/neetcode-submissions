class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_set<string> set1;

        vector<string> strs; 
        strs.push_back(s);
        strs.push_back(t);

        for (auto& str : strs) {
            vector<int> arr1(26, 0);
            for (char c : str) {
                int i = (c - 'a');
                arr1[i]++;
            } 
            
            string key =" ";
            for (auto& n : arr1) {
                key += ',' + to_string(n);
            }

            cout << key;

            if (set1.contains(key)) {
                return true; 
            } else {
                set1.insert(key);
            }
        }

        return false;

     


    }
};
