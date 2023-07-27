// Solved using the previous solutions and https://walkccc.me/LeetCode/problems/0079/

class Solution
{
public:
    int rows;
    int cols;
    bool exist(vector<vector<char>> &board, string word)
    {
        // # of rows in the board
        rows = board.size();
        // # of columns in the board
        cols = board[0].size();
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
    bool isSafe(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int s)
    {
        // s - current index in the word
        // check if the cell is within the board, if the character is in the word or if it is invalid
        if (!isSafe(x, y) || board[x][y] != word[s] || board[x][y] == '/')
        {
            return false;
        }
        // if the index matches the position in the word, we found it
        if (s == word.length() - 1)
        {
            return true;
        }
        // keep the original value
        const char cache = board[x][y];
        board[x][y] = '/';
        // check the neighbor cells
        const bool isExist = dfs(board, word, x + 1, y, s + 1) ||
                             dfs(board, word, x - 1, y, s + 1) ||
                             dfs(board, word, x, y + 1, s + 1) ||
                             dfs(board, word, x, y - 1, s + 1);
        // return the cell to the original state
        board[x][y] = cache;

        return isExist;
    }
};
