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
    bool balanced = true;
public:
    int visit(TreeNode *node, int level)
    {
        if (!node)
            return level;

        int nextLv = level + 1;

        int leftMax = visit(node->left, nextLv);
        int rightMax = visit(node->right, nextLv);
        int diff = leftMax - rightMax;
        if (diff > 1 || diff < -1)
        {
            balanced = false;
        }

        return max(leftMax, rightMax);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        visit(root, 0);

        return balanced;
    }
};
