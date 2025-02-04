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
    TreeNode* helper(vector<int> nums, int low, int high){
        if(low > high){
            return nullptr;
        }

        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, low, mid-1);
        root->right = helper(nums, mid+1, high);

        return root;
    }

    void inorder(TreeNode* root, vector<int>& nums){
        if(!root){
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return helper(sorted, 0, sorted.size()-1);
    }
};