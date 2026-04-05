/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    bool myBalanced = true;
    int PrivVisit(TreeNode *node)
    {
        if (!node)
            return 0;

        int leftHeight = PrivVisit(node->left);
        int rightHeight = PrivVisit(node->right);
        int diff = std::abs(leftHeight - rightHeight);
        if (diff > 1)
        {
            myBalanced = false;
        }

        return std::max(leftHeight + 1, rightHeight + 1);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        PrivVisit(root);

        return myBalanced;
    }
};
