// Solved based on the class notes
// Passed 2/2 cases
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // check if the node exists
        if (root == nullptr)
            return nullptr;
        // check if the node has the searched value
        if (root->val == val)
            return root;
        // check the children of the node to find the searched value, if exists
        if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
};
