// I used the class notes about level-order traverse of the tree for this task.
// In specific, the code for tracking level/depth/step
// Passed 2/2 cases

class Solution
{
public:
    Node *connect(Node *root)
    {
        // check that the tree is not empty
        if (root == nullptr)
            return nullptr;
        // a pointer to store the result
        Node *result = root;
        // a queue for level-order traverse of the tree
        queue<Node *> q;
        // put a root in a queue
        q.push(root);
        //
        while (!q.empty())
        {
            // store the size of the current level
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                // point at the beginning of the queue
                Node *node = q.front();
                // remove the first element of the queue
                q.pop();
                // point to the next node on this level
                if (i < sz - 1)
                    node->next = q.front();
                // check if the children exist and insert them into the queue
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        // return the root
        return result;
    }
};