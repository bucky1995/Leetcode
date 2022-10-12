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
    TreeNode* LCA;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        
        if(left && right){
            LCA = root;
            return true;
        }
        
        if(left || right){
            if(root == p || root == q){
                LCA = root;
            }
            return true;
        }
        
        if(root == p || root == q){
            return true;
        }
        
        return false;
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA = NULL;
        dfs(root, p, q);
        return LCA;
    }
};