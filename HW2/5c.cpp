// Originally solved without helper method but couldn't figure out how
// to return a null since the answer should be a vector.
// Referred to https://walkccc.me/LeetCode/problems/0145/ for help.

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // use helper method
        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode *root, vector<int> &ans)
    {
        // check if the node exists
        if (root == nullptr)
            return;
        // recursively check the children of the node
        postorder(root->left, ans);
        postorder(root->right, ans);
        // insert the nodes into vector
        ans.push_back(root->val);
    }
};
