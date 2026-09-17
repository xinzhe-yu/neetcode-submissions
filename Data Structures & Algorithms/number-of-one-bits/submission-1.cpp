class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = 0;
        for (r; n!=0; r++) {
            n &= (n - 1);
        }
        return r;   
    }
};
