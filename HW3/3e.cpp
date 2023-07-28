// Solved using the previous solutions and https://walkccc.me/LeetCode/problems/0079/

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // # of rows in the board
        int rows = board.size();
        // if the grid is empty, return 0 islands
        if (rows == 0)
            return 0;
        // # of columns in the board
        int cols = board[0].size();
        // if the grid is empty, return 0 islands
        if (cols == 0)
            return 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // if the words is found by dfs, return true
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    // check if the coordinates are inside the board
    bool isSafe(int i, int j, int rows, int cols)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int i)
    {
        int rows = board.size();
        int cols = board[0].size();
        // i - current index in the word
        // check if the cell is within the board, if the character is in the word or if it is invalid
        if (!isSafe(x, y, rows, cols) || board[x][y] != word[i] || board[x][y] == '/')
        {
            return false;
        }
        // if the index matches the position in the word, we found it
        if (i == word.length() - 1)
        {
            return true;
        }
        // keep the original value
        const char cache = board[x][y];
        board[x][y] = '/';
        // check the neighbor cells
        const bool isExist = dfs(board, word, x + 1, y, i + 1) ||
                             dfs(board, word, x - 1, y, i + 1) ||
                             dfs(board, word, x, y + 1, i + 1) ||
                             dfs(board, word, x, y - 1, i + 1);
        // return the cell to the original state
        board[x][y] = cache;

        return isExist;
    }
};
