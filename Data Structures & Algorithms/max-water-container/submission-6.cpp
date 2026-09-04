class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() - 1; 
        int L = 0;
        int R = n;


        int max_area = 0;
        while (L < R) {
            int area = min(heights[L], heights[R]) * (R - L);
            max_area = max(area, max_area);

            if (heights[L] < heights[R]) {
                L++;
            }
            else if (heights[L] >= heights[R]) {
                R--;
            }

        }

        return max_area;
    }
};
