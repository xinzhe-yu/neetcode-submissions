class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }

                pair<int, int> sqaureKey = {r / 3, c / 3};
                // create the pair key (square grid) 
                // based on r and c 

                // check if it duplicates in respective col, row and grid/ 
                if (rows[r].contains(board[r][c]) || cols[c].contains(board[r][c]) || squares[sqaureKey].contains(board[r][c])) {
                    return false; 
                }

                // if not insert into the map 
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[sqaureKey].insert(board[r][c]);
            }
        }
        return true;

        // every rc square
        
    }
};
