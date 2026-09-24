class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;

        int mL = L; //index
        int mR = R; 

        int water = 0;

        while (L < R) {
            if (height[mL] < height[mR]) {
                L++;
                if (height[L] >= height[mL]) {
                    mL = L;
                }
                water += height[mL] - height[L];
            } 
            else if (height[mL] >= height[mR]) {
                R--;
                if (height[R] >= height[mR]) {
                    mR = R;
                }
                water += height[mR] - height[R];
            }
        }
        return water; 
    }
};
