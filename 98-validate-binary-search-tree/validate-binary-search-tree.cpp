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
    // Helper function to check the validity of the BST
    bool validateBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        // Base case: an empty tree is a valid BST
        if (!root) {
            return true;
        }

        // Check if the current node violates the BST property
        if ((minNode && root->val <= minNode->val) || 
            (maxNode && root->val >= maxNode->val)) {
            return false;
        }

        // Recursively check left and right subtrees with updated boundaries
        return validateBST(root->left, minNode, root) && 
               validateBST(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root, nullptr, nullptr); // Initial boundary is unrestricted
    }
};
