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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int ans = dfs(root);
        if (ans == -1) {
            return false;
        }
        return true; 
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 1; 
        }

        int left = dfs(root->left);
        if (left == -1) {
            return -1;
        }

        int right = dfs(root->right);
        if (right == -1) {
            return -1; 
        }

        int diff = abs(left - right);
        if (diff > 1) {
            return -1; 
        }

        return max(left, right) + 1; 
    }
};
