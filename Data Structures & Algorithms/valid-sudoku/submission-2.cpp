class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // seems like a cotains duplicates with 3 params 
        
        //Row 
        for (int i = 0; i < board.size(); i++) {
            unordered_map<char,int> mp; 
            for (auto& c : board[i]) {
                if (c != '.') {
                    mp[c]++;
                    if (mp[c] > 1) {
                        return false; 
                    }
                }
                
            }

            unordered_map<char,int> cmp;
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] != '.') {
                    cmp[board[j][i]]++;
                    if (cmp[board[j][i]] > 1) {
                        return false; 
                    }
                }
            }

        }

        for (int grid_row = 0; grid_row < board.size(); grid_row += 3) {
            for (int grid_col = 0; grid_col < board.size(); grid_col += 3) {
                unordered_map<char,int> mp;
                for (int i = 0 + grid_row; i < 3 + grid_row; i++) {
                    for (int j = 0 + grid_col; j < 3 + grid_col; j++) {
                        if (board[i][j] != '.') {
                            mp[board[i][j]]++;
                            if (mp[board[i][j]] > 1) {
                                return false; 
                            }
                        }
                    }
                }
            }
        }

        return true; 


        

        
    }
};
