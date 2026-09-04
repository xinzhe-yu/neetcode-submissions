class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(); 
        unordered_map<int, unordered_set<char>> rows, cols; 
        map<pair<int, int>, unordered_set<char>> grid; 

        

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == '.') {
                    continue; 
                }

                pair<int, int> gridkey = { r / 3, c / 3}; 

                if (rows[r].contains(board[r][c]) || cols[c].contains(board[r][c]) || grid[gridkey].contains(board[r][c])) {
                    return false; 
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                grid[gridkey].insert(board[r][c]);
            }
        }

        return true; 
    }
};
