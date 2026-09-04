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
    int balance(TreeNode* root) {
        if (!root) {
            return 1;
        }
        int left = balance(root->left);
        if (left == -1) {
            return -1;
        }
        int right = balance(root->right);
        if (right == -1) {
            return -1;
        }

        int diff = abs(left-right);
        if (diff == 1 || diff == 0) {
            return 1 + max(left, right);
        } else {
            return -1;
        }

    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true; 

        if (balance(root) == -1){
            return false;
        }
        return true; 


    }
};
