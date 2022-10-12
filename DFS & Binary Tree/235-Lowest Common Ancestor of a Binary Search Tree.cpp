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
        if(root == NULL)
            return root;
        
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return root;
    }
};

class Solution_dfs {
public:
    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){
        path.push_back(node);
        if(node == target){
            return true;
        }
        
        if(node->val > target->val){
            dfs(node->left, target, path);
        }else{
            dfs(node->right, target, path);
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path, q_path;
        dfs(root, p, p_path);
        dfs(root, q, q_path);
        int size = min(p_path.size(), q_path.size());
        TreeNode* res = root;
        for(int i=0;i<size;i++){
            if(p_path[i] != q_path[i]){
                break;
            }
            res = p_path[i];
        }
        return res;
        
    }
};