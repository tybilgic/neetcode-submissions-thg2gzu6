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
    TreeNode *getRightLeaf(TreeNode *node)
    {
        if (node->right)
        {
            return getRightLeaf(node->right);
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        
        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // delete & fix & return node
            TreeNode *node = nullptr;
            if (root->left && root->right)
            {
                TreeNode *left = root->left;
                TreeNode *right = root->right;
                // get right leaf of the left child
                TreeNode *rightLeaf = getRightLeaf(left);
                rightLeaf->right = right;
                node = left;
            }
            else if (root->left && !root->right)
            {
                node = root->left;
            }
            else if (root->right && !root->left)
            {
                node = root->right;
            }

            delete root;
            return node;
        }

        return root;
    }
};