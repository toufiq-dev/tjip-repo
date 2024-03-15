class Solution {
public:
    // TC: O(M * N * 4 ^ L), M, N dimentions of board, L = |word|
    // SC: O(M * N)
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (searchIn(board, word, i, j, 0)) 
                        return true;
                }
            }
        }

        return false;
    }
private:
    static constexpr int dir[] = {-1, 0, 1, 0, -1};
    bool visited[6][6];

    bool searchIn(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if (idx == word.size()) 
            return true;
        
        if (x < 0 || y < 0 || x >= board.size() || y >= board[x].size() || visited[x][y] == 1) 
            return false;
        
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];
            if (board[x][y] == word[idx] && searchIn(board, word, dx, dy, idx + 1))
                return true;
        }

        visited[x][y] = 0;
        return false;
    }
};