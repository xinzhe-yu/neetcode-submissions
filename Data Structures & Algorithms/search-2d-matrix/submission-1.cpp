class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0;
        int R = matrix.size() - 1;

        int flag = 0; 
        int m = -1; 
        while (L <= R) {
            m = (L + R) / 2;

            if (target < matrix[m][0]) {
                R = m - 1;
            } else if (target > matrix[m].back()) {
                L = m + 1; 
            } else if (target >= matrix[m][0] && target <= matrix[m].back()) {
                flag = 1; 
                break;
            }
        }

        if (flag == 0) {
            return false; 
        }

        L = 0;
        R = matrix[m].size() - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (target < matrix[m][mid]) {
                R = mid - 1;
            } else if (target > matrix[m][mid]) {
                L = mid + 1; 
            } else if (target == matrix[m][mid]) {
                return true; 
            }
        }

        return false; 
    }
};
