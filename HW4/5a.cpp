// Created by using class notes and the Prim's Algorithm's code from https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

class Solution {
public:
typedef pair<int,int> pii;
    int minCostConnectPoints(vector<vector<int>>& points) {
        // create the adjacency list and calculate the distance between all points
        vector<vector<pair<int, int>>> adjList(points.size());
        for (int i; i < points.size(); i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < points.size(); j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cost = abs(x2-x1) + abs(y2-y1);
                // fill the adj list with the distance and weights
                adjList[i].push_back({j, cost});
                adjList[j].push_back({i, cost});
            }
        }
        // create a priority queue to store edges with their weights
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // create a vector to store visited points, set all to unvisited
        vector<bool> visited(points.size(), false);
        // variable to store the result
        int res = 0;
        // insert the first vertex 0
        pq.push({0, 0});
        // perform Prim's algorithm to find the Minimum Spanning Tree
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;  // Weight of the edge
            int u = p.second;  // Vertex connected to the edge
            
            if(visited[u] == true){
                continue;  // Skip if the vertex is already visited
            }
            
            res += wt;  // Add the edge weight to the result
            visited[u] = true;  // Mark the vertex as visited
            
            // Explore the adjacent vertices
            for(auto v : adjList[u]){
                int vertex = v.first;
                int edgeWeight = v.second;
                if(visited[vertex] == false){                
                    pq.push({edgeWeight, vertex});  // Add the adjacent edge to the priority queue
                }
            }
        }
        return res;
    }
};
