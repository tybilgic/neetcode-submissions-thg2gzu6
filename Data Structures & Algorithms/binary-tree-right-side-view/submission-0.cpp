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
    using NodeLevel = pair<TreeNode *, int>;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        
        queue<NodeLevel> q;
        int currLevel = 0;

        q.push({root, 0});
        while (!q.empty())
        {
            auto nodepair = q.front(); q.pop();
            auto node = nodepair.first;
            auto nodeLevel = nodepair.second;
            
            if (currLevel == nodeLevel)
            {
                currLevel++;
                res.push_back(node->val);
            }

            if (node->right)
                q.push({node->right, nodeLevel + 1});
            if (node->left)
                q.push({node->left, nodeLevel + 1});
        }

        return res;
    }
};
