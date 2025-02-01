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
    bool helper(TreeNode* root, TreeNode* n, vector<TreeNode*>& path){
        if(!root){
            return false;
        }

        path.push_back(root);

        if(root == n){
            return true;
        }

        if(helper(root->left, n, path) || helper(root->right, n, path)){
            return true;
        }

        path.pop_back();    // BackTrack... If not found that node!
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        if(!helper(root, p, path1) || !helper(root, q, path2)){
            return root;
        }

        TreeNode* lca = root;
        for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++){
            if(path1[i] != path2[j]){
                break;
            }
            lca = path1[i];
        }
        return lca;
    }
};