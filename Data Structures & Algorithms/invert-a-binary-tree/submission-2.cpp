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

// Breath First Search
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode* element = que.front();
            que.pop();

            TreeNode* tmp = element->left;
            element->left = element->right;
            element->right = tmp;

            if (element->left != NULL) que.push(element->left);
            if (element->right != NULL) que.push(element->right);
        }

        return root;
    }
};
