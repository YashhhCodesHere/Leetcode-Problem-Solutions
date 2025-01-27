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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> currLevel;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr){
                result.push_back(currLevel);
                currLevel.clear(); 
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                currLevel.push_back(curr -> val);
                
                if(curr -> left){
                    q.push(curr -> left);
                }

                if(curr -> right){
                    q.push(curr -> right);
                }
            }
        }
        return result;
    }
};