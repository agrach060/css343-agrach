// I started solving this problem by my self but I was going in the wrong direction
// so I had to look up the solution, which I processed and understood from: https://www.youtube.com/watch?v=GSE0-dReL6Y

class Solution
{
public:
    int rows;
    int cols;
    int shortestBridge(vector<vector<int>> &grid)
    {
        // # of rows in the grid
        rows = grid.size();
        // # of columns in the grid
        cols = grid[0].size();
        // create a set to store the cells that have been visited
        set<pair<int, int>> visited;
        // traverse through the grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                //  found an island
                if (grid[i][j] == 1)
                {
                    // find where the island ends
                    dfs(grid, i, j, visited);
                    // return the shortest bridge to the second island
                    return bfs(grid, visited);
                }
            }
        }
        return -1;
    }

    // possible directions to move from a cell
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // check if the coordinates are inside the grid
    bool isSafe(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    // find how big is the island
    void dfs(vector<vector<int>> &grid, int i, int j, set<pair<int, int>> &visited)
    {
        // check if the cell is within the grid, if it has been visited, or it's water
        if (!isSafe(i, j) || grid[i][j] == 0 || visited.find({i, j}) != visited.end())
        {
            return;
        }
        // mark the cell as visited
        visited.insert({i, j});

        // check the neighbor cells and dp the dfs on them
        for (auto &it : directions)
        {
            int a = i + it[0];
            int b = j + it[1];

            dfs(grid, a, b, visited);
        }
    }

    int bfs(vector<vector<int>> &grid, set<pair<int, int>> &visited)
    {
        queue<pair<int, int>> q;
        // add all the previously visited cells in a queue
        for (auto &it : visited)
        {
            q.push(it);
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
                    if (isSafe(a, b) && visited.find({a, b}) == visited.end())
                    {
                        // if the second island is found, return the current level
                        if (grid[a][b] == 1)
                        {
                            return level;
                        }
                        // if the second island is not yet found, mark the cell
                        // as visited and explore the neighbors
                        visited.insert({a, b});
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
