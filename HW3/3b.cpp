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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // check if the node exists
        if(node == nullptr)
            return nullptr;
        vector<Node*> visited(101, nullptr);
        // create a new node for the clone graph
        Node* copy = new Node(node->val);
        // mark the node as visited
        visited[node->val] = copy;
        // visit all the neightbours of the node
        for(Node* curr : node->neighbors){
            if(visited[curr->val] == nullptr){
                // if the node hasn't been visited, create this node for the clone graph
                Node* newNode = new Node(curr->val);
                // make it a copy node's neighbor
                copy->neighbors.push_back(newNode);
                // perform the dfs on this node
                dfs(curr, newNode, visited);
            }else{
                // if the node has been visited, add the node from the visited array as its neighbor
                copy->neighbors.push_back(visited[curr->val]);
            }
        }
        return copy;
    }

    void dfs(Node* curr, Node* node, vector<Node*>& visited){
        // curr - current original node
        // node - current clone node
        // mark the newly made node as visited 
        visited[node->val] = node;
        // go through all the adjacent nodes of the original node
        for(Node* adj : curr->neighbors){
            // if the neighbor is not visited
            if(visited[adj->val] == nullptr){
                // create a new node
                Node* newNode = new Node(adj->val);
                // make it a current node's neighbor
                node->neighbors.push_back(newNode);
                dfs(adj, newNode, visited);
            }else{
                // if the node has been visited, take this node from the visited array  
                // and make it a current node's neighbor
                node->neighbors.push_back(visited[adj->val]);
            }
        }
    }
};
