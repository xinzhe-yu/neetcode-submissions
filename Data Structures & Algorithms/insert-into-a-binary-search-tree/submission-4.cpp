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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root; 
        // Recursive apporach 
        // For each node if val greater go R, less go L 
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        // Base case - Find the value ?
        if (curr->right && val > curr->val) {
            curr = curr->right;
            insertIntoBST(curr, val);
        } else if (curr->left && val < curr->val){
            curr = curr->left;
            insertIntoBST(curr, val); 
        }

        else if (val > curr->val) {
            curr->right = new TreeNode(val);
        } else if (val < curr->val) {
            curr->left = new TreeNode(val);
        } else { 
            return root;
        }

        return root;
    }
};