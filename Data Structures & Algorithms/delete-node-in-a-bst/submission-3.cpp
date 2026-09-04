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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // Base case
        if (!root) {
            return nullptr;
        }

        // Search
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            // What probelm solved?
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {  //found 
            // Case 0,1 children
            if (!root->right) {
                return root->left;
            } else if (!root->left) {
                return root->right;
            } else if (root->left && root->right) { // Case 2 children. 
                //go right, then all the way left
                TreeNode* curr = root->right;
                while(curr->left) {  //Find Right-smallest
                    curr = curr->left;
                }

                root->val = curr->val; //replace node
                root->right = deleteNode(root->right, curr->val);
            }  
        }
        return root; 

    }
};