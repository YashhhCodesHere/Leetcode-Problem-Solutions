/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or we find p or q, return root
        if (!root) {
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        // Search left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, current node is the LCA
        if (left && right) {
            return root;
        }

        // If only one subtree has a valid result, return that one
        return left ? left : right;
    }
};