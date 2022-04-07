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
    bool dfs(TreeNode* node, TreeNode* min, TreeNode* max){
        if(node == NULL){
            return true;
        }
        if(min!=NULL && node->val <= min->val){
            return false;
        }
        if(max!=NULL && node->val >= max->val){
            return false;
        }

        return dfs(node->left, min, node) && dfs(node->right, node, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
};