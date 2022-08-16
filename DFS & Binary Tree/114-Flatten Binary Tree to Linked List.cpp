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
    vector<TreeNode*> buffer;
    void getNode(TreeNode* root){
        if(root == NULL)    return;
        getNode(root->left);
        getNode(root->right);
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        root->left = NULL;
        root->right = left;
        
        TreeNode* p = root;
        while(p->right!=NULL)   p = p->right;
        p->right = right;
    }
    
    void flatten(TreeNode* root) {
        getNode(root);
    }
};