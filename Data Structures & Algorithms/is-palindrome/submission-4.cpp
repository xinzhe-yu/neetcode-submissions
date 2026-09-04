class Solution {
public:
    bool isPalindrome(string s) {
        //make 2 pointers
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }

            while (r > l && !isalnum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false; 
            }
            l++;
            r--;
        }
        return true;
    }
};
