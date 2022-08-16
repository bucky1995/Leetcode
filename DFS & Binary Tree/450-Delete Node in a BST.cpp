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
    TreeNode* findSmallest(TreeNode* root){
        if(root->left == NULL){
            return root;
        }    
        return findSmallest(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)    return NULL;
        if(root->val == key){
            if(root->left == NULL)  return root->right;
            if(root->right == NULL) return root->left;
            TreeNode* p = findSmallest(root->right);
            root->right = deleteNode(root->right, p->val);
            
            p->left = root->left;
            p->right = root->right;
            
            root = p;
        } else if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};