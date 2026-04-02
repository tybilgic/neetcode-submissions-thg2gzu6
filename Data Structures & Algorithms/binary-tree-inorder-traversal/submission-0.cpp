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
public:
    void visitNode(TreeNode *node, vector<int>& v)
    {
        if (!node)
            return;
        
        visitNode(node->left, v);
        v.push_back(node->val);
        visitNode(node->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        visitNode(root, res);
        return res;
    }
};