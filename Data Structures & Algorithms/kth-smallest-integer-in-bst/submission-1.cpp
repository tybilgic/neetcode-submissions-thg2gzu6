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
    vector<int> privInorderTraversal(TreeNode* node) {
        vector<int> res;
        stack<TreeNode *> st;

        while (node || !st.empty())
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }

        return res;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec = privInorderTraversal(root); // O(n)

        return vec[k - 1];
    }
};
