class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int L = 0; 
        int R = heights.size() - 1;

        int max_area = 0; 

        while (L <= R) {
            int area = (R - L) * min(heights[L], heights[R]);
            max_area = max(max_area, area);

            if (heights[L] < heights[R]) {
                L++;
            } else if (heights[L] >= heights[R]) {
                R--; 
            }
        }

        return max_area; 


    }
};
