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
        if (dfs(root) == -1) {
            return false;
        }
        return true;
    }

    int dfs(TreeNode* root) {

        if (root == NULL) {
            return 1;
        }

        int left = dfs(root->left);
        if (left == -1) return -1;
        int right = dfs(root->right);
        if (right == -1) return -1;

        int diff = left - right;
        if (abs(diff) == 1 || diff == 0) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
        

    }
};

// each root need go left and right 
// each left right solve sub problem and returns their height
// if sub problem is null recursive null to end
// 
