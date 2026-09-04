class Solution {
public:
    int trap(vector<int>& height) {
        // Min(leftmax, rightmax) - height[i];

        int L = 0, R = height.size() - 1;
        int maxL = 0, maxR = 0; 
        int water = 0;

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
