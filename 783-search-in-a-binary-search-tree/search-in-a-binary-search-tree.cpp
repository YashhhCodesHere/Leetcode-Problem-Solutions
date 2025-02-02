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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the node is null or the node's value matches the target
        if (!root || root->val == val) {
            return root;
        }
        
        // Use the BST property to optimize the search
        if (val < root->val) {
            // Search in the left subtree
            return searchBST(root->left, val);
        } else {
            // Search in the right subtree
            return searchBST(root->right, val);
        }
    }
};