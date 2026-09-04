// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size(); 
        vector<vector<Pair>> ans; 
        if (n == 0) { return ans; }
        ans.push_back(pairs);
        for (int i = 0; i < n-1; i++) {
            auto it = pairs.begin() + 1 + i;
            while (it != pairs.begin() && it->key < (it-1)->key) {
                std::iter_swap(it, it-1);
                it--; 
            }
            ans.push_back(pairs);
        }
    return ans;
    }
};
