// Solved using the class notes and
// the help from this video: https://www.youtube.com/watch?v=uspsIxavTzA

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // # of rows in the grid
        int rows = grid.size();
        // if the grid is empty, return 0 islands
        if (rows == 0)
            return 0;
        // # of columns in the grid
        int cols = grid[0].size();
        // if the grid is empty, return 0 islands
        if (cols == 0)
            return 0;

        int count = 0;
        // create a struct to keep track of visited nodes
        unordered_set<int> visited;
        // check how many islands are in the grid by exploring the neighbors of 1s
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, visited, rows, cols);
                }
            }
        }
        return count;
    }
    // check if the cell is within the grid
    bool isSafe(int i, int j, int rows, int cols)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    void dfs(vector<vector<char>> &grid, int x, int y, unordered_set<int> &visited, int rows, int cols)
    {

        // check if the coordinates are inside the grid or if it is water or the coordinates are outside the grid
        if(!isSafe(x, y, rows, cols) || grid[x][y] == '0' || visited.find(x * cols + y) != visited.end(){
            return;
        }

        // Mark the cell as visited
        visited.insert(x * cols + y);
        
        grid[x][y] = '0';
        // look for the neighbors in 4 directions
        if(x+1 < grid.size() && grid[x+1][y] == '1'){
            dfs(grid, x + 1, y, visited, rows, cols);
        }
        if(x-1 >= 0 && grid[x-1][y] == '1'){
            dfs(grid, x - 1, y, visited, rows, cols);
        }
        if(y-1 >= 0 && grid[x][y-1] == '1'){
            dfs(grid, x, y - 1, visited, rows, cols);
        }
        if(y+1 < grid[0].size() && grid[x][y+1] == '1'){
            dfs(grid, x, y + 1, visited, rows, cols);
        }
    }
};
