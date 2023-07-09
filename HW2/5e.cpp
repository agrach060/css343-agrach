// Solved based on the class notes

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // check if the node exists
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};