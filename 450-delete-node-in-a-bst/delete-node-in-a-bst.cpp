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
    // Helper Function
    TreeNode* getInorderSuccessor(TreeNode* root){
        while(root && root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            // No Child
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // One Child
            if(root->left == nullptr || root->right == nullptr){
                TreeNode* child = (root->left == nullptr) ? root->right : root->left;
                delete root;
                return child;
            }
            // Two Children -> swap with Inorder Successor
            TreeNode* IS = getInorderSuccessor(root->right);
            root->val = IS->val;
            root->right = deleteNode(root->right, IS->val);
        }
        return root;
    }
};