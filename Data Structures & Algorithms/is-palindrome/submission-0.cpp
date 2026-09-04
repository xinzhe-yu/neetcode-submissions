class Solution {
public:
    bool isPalindrome(string s) {
        char* left = &s[0];
        char* right = &s[s.size() - 1];

      while (left < right) {
            // skip non-alphanumeric from the left
            while (left < right && !std::isalnum(static_cast<unsigned char>(*left))) {
                ++left;
            }
            // skip non-alphanumeric from the right
            while (left < right && !std::isalnum(static_cast<unsigned char>(*right))) {
                --right;
            }

            if (std::tolower(static_cast<unsigned char>(*left)) != std::tolower(static_cast<unsigned char>(*right))) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    
};
