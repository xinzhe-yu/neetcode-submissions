class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int water = 0;
        int maxL = 0, maxR = 0;
        while (L < R) {
            if (height[L] < height[R]) {
                
                maxL = max(height[L], maxL);
                water += maxL - height[L];
                L++;
            } else {
                
                maxR = max(height[R], maxR);
                water += maxR - height[R];
                R--;
            }
        }
        return water; 
    }
};
