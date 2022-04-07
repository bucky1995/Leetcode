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
    vector<int> res;
    void dfs_inorder(TreeNode* node){
        if(node == NULL){
            return;
        }
        dfs_inorder(node->left);
        res.push_back(node->val);
        dfs_inorder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //dfs_inorder(root);
        if(root == NULL){
            return {};
        }
        //dfs_inorder(root);
        vector<TreeNode*> buffer;
        unordered_set<TreeNode*> used;
        buffer.push_back(root);
        while(!buffer.empty()){
            while(buffer.back()->left != NULL && used.find(buffer.back()->left) == used.end()){
                buffer.push_back(buffer.back()->left);
                used.insert(buffer.back());
            }
            res.push_back(buffer.back()->val);
            TreeNode* node = buffer.back();
            buffer.pop_back();
            if(node->right && used.find(node->right) == used.end())
                buffer.push_back(node->right);
        }
        return res;
    }
};