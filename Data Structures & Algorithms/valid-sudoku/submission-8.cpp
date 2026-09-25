class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> grid;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                pair<int, int> gridkey = {row / 3, col / 3};

                if (board[row][col] == '.') {
                    continue;
                }

                // row
                if (rows[row].contains(board[row][col])) {
                    return false;
                } else {
                    rows[row].insert(board[row][col]);
                }

                // col
                if (cols[col].contains(board[row][col])) {
                    return false;
                } else {
                    cols[col].insert(board[row][col]);
                }

                // grid
                if (grid[gridkey].contains(board[row][col])) {
                    return false;
                } else {
                    grid[gridkey].insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
