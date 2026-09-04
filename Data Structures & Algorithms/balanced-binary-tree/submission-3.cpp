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
        if (!root) return true;

        int l, r;
        r = traverse(root->right);
        l = traverse(root->left);
        if (l == -1 || r == -1) return false;
        int tmp = l-r;
        if (tmp == 0 || tmp == 1 || tmp == -1) {
            return true;
        }
        return false;
        
    }

    int traverse(TreeNode* root) {
        int left = 0; 
        int right = 0;
        if (!root) {
            return 1;
        }
        left += traverse(root->left);
        right += traverse(root->right);

        // check the same 
        int tmp = left-right; 
        if (tmp == 0 || tmp == 1 || tmp == -1) {
            return 1 + max(left, right);
        }
        return -1;
    }

};
