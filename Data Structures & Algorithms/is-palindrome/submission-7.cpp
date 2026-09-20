class Solution {
   public:
    bool isPalindrome(string s) {
        // 2 pointers, skip white space

        int L = 0;
        int R = s.size() - 1;

        while (L < R) {
            while (L < R && !isalnum(s[L])) {
                L++;
            }

            while (L < R && !isalnum(s[R])) {
                R--;
            }

            if (tolower(s[L]) != tolower(s[R])) {
                return false;
            }

            L++;
            R--;
        }

        return true;
    }
};
