// Solved using the class notes and
// the help from this video: https://www.youtube.com/watch?v=uspsIxavTzA

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // define the number of vectors in the outer vector
        int rows = grid.size();
        // if the grid is empty, return 0 islands
        if (rows == 0)
            return 0;
        // define the number of vectors in the inner vector
        int cols = grid[0].size();
        // if the grid is empty, return 0 islands
        if (cols == 0)
            return 0;

        int count = 0;
        // check how many islands are in the grid by exploring the neighbors of 1s
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';
        // look for the neighbors in 4 directions
        if (x + 1 < grid.size() && grid[x + 1][y] == '1')
        {
            dfs(grid, x + 1, y);
        }
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
        {
            dfs(grid, x - 1, y);
        }
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
        {
            dfs(grid, x, y - 1);
        }
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
        {
            dfs(grid, x, y + 1);
        }
    }
};
