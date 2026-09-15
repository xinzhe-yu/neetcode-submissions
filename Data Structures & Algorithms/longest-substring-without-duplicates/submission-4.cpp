class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;

        int L = 0;
        int max_count = 0;

        int count = 0;
        for (int R = 0; R < s.size(); R++) {
            count++;
            
            while (window.contains(s[R])) {
                //shrink to delete duplicate
                window.erase(s[L]);
                L++;
                count--;
            }

            window.insert(s[R]);
            max_count = max(max_count, count);
            
        }

        return max_count;
    }
};
