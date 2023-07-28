// I started solving this problem by my self but I was going in the wrong direction
// so I had to look up the solution, which I processed and understood from: https://www.youtube.com/watch?v=GSE0-dReL6Y

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
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
        // create a set to store the cells that have been visited
        unordered_set<int> visited;
        bool islandFound = false;
        // traverse through the grid
        for (int i = 0; i < rows && !islandFound; i++)
        {
            for (int j = 0; j < cols && !islandFound; j++)
            {
                //  found an island
                if (grid[i][j] == 1)
                {
                    // find where the island ends
                    dfs(grid, i, j, visited, rows, cols);
                    islandFound = true;
                }
            }
        }
        // return the shortest bridge to the second island or -1
        return bfs(grid, visited, rows, cols);
    }

    // possible directions to move from a cell
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // check if the coordinates are inside the grid
    bool isSafe(int i, int j, int rows, int cols)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    // find how big is the island
    void dfs(vector<vector<int>> &grid, int i, int j, unordered_set<int> &visited, int rows, int cols)
    {
        // check if the cell is within the grid, if it has been visited, or it's water
        if (!isSafe(i, j, rows, cols) || grid[i][j] == 0 || visited.find(i * cols + j) != visited.end())
        {
            return;
        }
        // mark the cell as visited
        visited.insert(i * cols + j);

        // check the neighbor cells and dp the dfs on them
        for (auto &it : directions)
        {
            int a = i + it[0];
            int b = j + it[1];

            dfs(grid, a, b, visited, rows, cols);
        }
    }

    int bfs(vector<vector<int>> &grid, unordered_set<int> &visited, int rows, int cols)
    {
        queue<pair<int, int>> q;
        // add all the previously visited cells in a queue
        for (auto &it : visited)
        {
            q.push({it / cols, it % cols});
        }
        // store the distance from starting island
        int level = 0;
        // traverse the queue
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                // take the top of the queue
                pair<int, int> p = q.front();
                q.pop();
                int first = p.first;
                int second = p.second;
                // explore the neighbors of the cell in 4 directions
                for (auto &dir : directions)
                {
                    int a = first + dir[0];
                    int b = second + dir[1];
                    // check if the cell is safe to visit
                    if (isSafe(a, b, rows, cols) && visited.find(a * cols + b) == visited.end())
                    {
                        // if the second island is found, return the current level
                        if (grid[a][b] == 1)
                        {
                            return level;
                        }
                        // if the second island is not yet found, mark the cell
                        // as visited and explore the neighbors
                        visited.insert(a * cols + b);
                        q.push({a, b});
                    }
                }
            }
            // move on to the next level
            level++;
        }
        return level;
    }
};
