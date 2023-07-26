// Solved using class notes and
// https://www.youtube.com/watch?v=_BGK0kpE4oE as a reference

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // define adjacency list
        vector<vector<int>> adjList(numCourses);
        // iterate through edges
        for (vector<int> &courses : prerequisites)
        {
            // point the second element to the first
            adjList[courses[1]].push_back(courses[0]);
        }
        // create a "stack"
        vector<int> s;
        vector<int> visited(numCourses, 0);
        // check if the graph has a cycle
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0 && dfs(i, adjList, s, visited))
            {
                // if the node is unvisited and the dfs returned "true",
                // then there is a cycle in the graph
                // return empty vector since no such order exists
                return {};
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }

    bool dfs(int i, vector<vector<int>> &adjList, vector<int> &s, vector<int> &visited)
    {
        // set the state of each node as "currently visiting"
        visited[i] = 1;
        // visit the neighbours of each node
        for (int v : adjList[i])
        {
            // cycle is found
            if (visited[v] == 1)
            {
                return true;
            }
            // if the node has not been visited, perform another dfs
            if (visited[v] == 0 && dfs(v, adjList, s, visited))
            {
                return true;
            }
        }
        // mark the node as visited
        visited[i] = 2;
        // the "stack" is now holding the elements in reversed topological order
        s.push_back(i);
        // return that the graph doesn't have a cycle in it
        return false;
    }
};
