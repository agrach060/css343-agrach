// Solved until how to find the smallest node.
// Referred to solution on https://walkccc.me/LeetCode/problems/0450/

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // check if the node exist
        if (root == nullptr)
            return nullptr;
        // delete the node and check if it has children
        if (root->val == key)
        {
            // left child doesn't exist
            if (root->left == nullptr)
                return root->right;
            // right child doesn't exist
            if (root->right == nullptr)
                return root->left;
            // both children exist
            // find the leftest child in the right subtree
            TreeNode *minNode = getMin(root->right);
            // delete smallest nodes in the right subtree
            root->right = deleteNode(root->right, minNode->val);
            // replace the root with the smallest node
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        }
        else if (root->val < key)
        {
            // check the right subtree
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // check the left subtree
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    // find the smallest node
    TreeNode *getMin(TreeNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }
};
