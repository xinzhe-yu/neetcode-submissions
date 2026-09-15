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
    TreeNode* invertTree(TreeNode* root) {
       if (root == nullptr) { return root; }
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }


        // swap
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        dfs(root->left);
        dfs(root->right);
    }
};
