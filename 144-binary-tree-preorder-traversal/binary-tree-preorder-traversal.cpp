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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root){
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            
            result.push_back(curr -> val);

            if(curr -> right){  //Right child is pushed first as STACK FOLLOW LIFO
                s.push(curr -> right);
            }
            //so that the left child is processed first when popped from the stack.
            if(curr -> left){
                s.push(curr -> left);
            }
        }
        return result;
    }
};