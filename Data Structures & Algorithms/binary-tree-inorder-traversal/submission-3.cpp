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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode *> nodestack;

        if (!root)
            return res;
        
        TreeNode *node = root;

        while (true)
        {
            if (node)
            {
                if (node->left)
                {
                    nodestack.push(node);
                    node = node->left;
                    continue;
                }
                else
                {
                    res.push_back(node->val);

                    if (node->right)
                    {
                        node = node->right;
                        continue;
                    }
                }
            }
            
            if (!nodestack.empty())
            {
                node = nodestack.top();
                nodestack.pop();
                res.push_back(node->val);
                node = node->right;
            }
            else
            {
                break;
            }

        }

        return res;
    }
};