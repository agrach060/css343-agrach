// Solved using class notes and
// https://www.youtube.com/watch?v=_BGK0kpE4oE as a reference

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // define adjacency list
        vector<vector<int>> adjList(numCourses);
        // create adjacency list
        // iterate through edges
        for (vector<int> &edges : prerequisites)
        {
            // point the second element to the first
            adjList[edges[1]].push_back(edges[0]);
        }

        // create a vector to store the topological order
        vector<int> ans;
        // create a vector to store visited nodes, set all to unvisited
        // 0 - unvisited, 1 - being visited, 2 - visited
        vector<int> visited(numCourses, 0);
        // check if the graph has a cycle
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0 && !dfs(i, adjList, ans, visited))
            {
                // if the node is unvisited and the dfs returned "true",
                // then there is a cycle in the graph
                // return empty vector since no such order exists
                return {};
            }
        }
        return ans;
    }

    bool dfs(int i, vector<vector<int>> &adjList, vector<int> &result, vector<int> &visited)
    {
        // we found the cycle
        if (visited[i] == 1)
        {
            return false;
        }
        // the node is already visited, don't need to explore again
        if (visited[i] == 2)
        {
            return true;
        }
        // set the state of each node as "currently visiting"
        visited[i] = 1;

        // visit the neighbours of each node
        for (int neighbor : adjList[i])
        {
            if (!dfs(neighbor, adjList, result, visited))
            {
                return false;
            }
        }
        // mark as visited
        visited[i] = 2;
        // reverse the result
        result.insert(result.begin(), i);

        return true;
    }
};