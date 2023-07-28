// Solved using the class notes and
// this video for concept idea of the dfs: https://www.youtube.com/watch?v=f2EfGComRKM

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        // check if the node exists
        if (node == nullptr)
        {
            return nullptr;
        }
        // create a struct to keep track of visited nodes
        unordered_map<int, Node *> visited;
        // perform the dfs on the node and return the cloned graph
        return dfs(node, visited);
    }

    Node *dfs(Node *node, unordered_map<int, Node *> &visited)
    {
        // if the node has been visited, return the clone
        if (visited.find(node->val) != visited.end())
        {
            return visited[node->val];
        }
        // copy the value of the original node into the new node
        Node *copy = new Node(node->val);
        visited[node->val] = copy;
        // traverse through the neighbors and return their dfs
        for (Node *neighbor : node->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor, visited));
        }

        return copy;
    }
};