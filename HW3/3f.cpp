// Solved using class nodes and https://www.youtube.com/watch?v=aoPQ5tGY_kM&t=61s

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // create an adjacency list with n+1 elements
        vector<vector<pair<int, int>>> adj(n + 1);
        // create adjacency list
        // iterate through edges
        for (auto &edges : times)
        {
            adj[edges[0]].push_back({edges[1], edges[2]});
        }

        return dijkstra(adj, n, k);
    }

    int dijkstra(vector<vector<pair<int, int>>> &graph, int n, int currVer)
    {
        //    create the struct that will store nodes with the minimum time taken value as the first element of the pair
        priority_queue<pair<int, int>> pq;
        //   make the first element of the queue a node with 0 time
        pq.push({0, currVer});
        // stores the minimum time taken to reach each node from the starting node
        vector<int> timeTaken(n + 1, INT_MAX);
        //   initial time to reach the starting node
        timeTaken[currVer] = 0;

        while (!pq.empty())
        {
            // get the first element from the queue with the minimum time
            auto topVer = pq.top();
            pq.pop();
            // check the neighbors
            for (auto adjNodes : graph[topVer.second])
            {
                // if a shorter path is found to reach the adjacent node, update the timeTaken and add it to the queue
                if (timeTaken[adjNodes.first] > timeTaken[topVer.second] + adjNodes.second)
                {
                    timeTaken[adjNodes.first] = timeTaken[topVer.second] + adjNodes.second;
                    pq.push({timeTaken[adjNodes.first], adjNodes.first});
                }
            }
        }
        // check if the nodes are reachable
        for (int i = 1; i <= n; i++)
        {
            if (timeTaken[i] == INT_MAX)
            {
                return -1;
            }
        }
        // return the maximum time taken to reach any node from the starting node
        return *max_element(timeTaken.begin() + 1, timeTaken.end());
    }
};
