class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0;
        int R = matrix.size() - 1;

        
        int row; 

        while (L <= R) {
            int midpoint = (L + R) / 2;
            if (target < matrix[midpoint][0]) {
                R = midpoint - 1;
            } else if (target > matrix[midpoint].back()) { // use .back() to dodge midpoint + 1 case 
                L = midpoint + 1;
            } else {
                row = midpoint;
                break;
            }
        }

        if (row == -1) return false; //important step means row was not found

        L = 0;
        R = matrix[row].size() - 1;

        while (L <= R) {
            int m = (L + R) / 2;
            if (target > matrix[row][m]) {
                L = m + 1;
            }
            else if (target < matrix[row][m]) {
                R = m - 1;
            }
            else if (target == matrix[row][m]) {
                return true; 
            }
        }

        return false; 


    }
};
