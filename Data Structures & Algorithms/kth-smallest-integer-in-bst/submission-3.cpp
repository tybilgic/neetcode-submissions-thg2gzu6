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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;

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
            if (res.size() == k)
                return res.back();
            node = node->right;
        }

        return res.back();
    }
};
