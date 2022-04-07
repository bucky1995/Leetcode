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
    unordered_set<TreeNode*> hash;
    TreeNode* dfs(TreeNode* node){
        if(node == NULL){
            return node;
        }
        
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        
        if(left!= NULL && right != NULL){
            return node;
        }
        
        if(hash.find(node) != hash.end()){
            return node;
        }
        
        return left == NULL ? right : left;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        hash.insert(nodes.begin(), nodes.end());
        return dfs(root);
    }
};