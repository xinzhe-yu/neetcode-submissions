class Solution {
public:
    int trap(vector<int>& height) {
        // Min(maxL, maxR) - height[i]
        int n = height.size();
        vector<int> maxL(n), maxR(n), min_arr(n), ans(n); 
        int maximum = 0; 
        int water = 0; 
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, height[i]);
            maxL[i] = maximum; 
        }

        maximum = 0;
        for (int i = n - 1; i >= 0; i--) {
            maximum = max(maximum, height[i]);
            maxR[i] = maximum; 
        }

        for (int i = 0; i < n; i++) {
            min_arr[i] = min(maxL[i], maxR[i]);
        }

        for (int i = 0; i < n; i++) {
            if (min_arr[i] - height[i] > 0) {
                water += min_arr[i] - height[i];
            }
        }

        return water;




    }
};
