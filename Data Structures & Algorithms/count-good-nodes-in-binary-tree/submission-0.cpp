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
    int goodNodes(TreeNode* root) {
        return recGood(root, root);
    }

    int recGood(TreeNode* root, TreeNode* parent)
    {
        if (!root) return 0;

        int addend = 0;
        if (root->val >= parent->val) addend = 1;

        root->val = max(root->val, parent->val);

        return addend + recGood(root->left, root) + recGood(root->right, root);
    }
};
