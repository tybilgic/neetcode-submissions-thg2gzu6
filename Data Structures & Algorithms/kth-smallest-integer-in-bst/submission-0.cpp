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
    vector<int> myVec;
    void privVisit(TreeNode *node)
    {
        if (!node)
            return;
        
        myVec.push_back(node->val);

        privVisit(node->left);
        privVisit(node->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        /* O(n) + O(N*logN) */
        privVisit(root);
        sort(myVec.begin(), myVec.end());

        return myVec[k - 1];
    }
};
