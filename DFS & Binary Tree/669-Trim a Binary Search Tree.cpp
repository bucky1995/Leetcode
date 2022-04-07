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
    void left_trim(TreeNode* root, int low){
        if(root == NULL || root->left == NULL){
            return;
        }
        while(root->left!=NULL && root->left->val < low){
            TreeNode* temp = root->left->right;
            root->left = temp;
        }
        
        left_trim(root->left, low);
    }
    void right_trim(TreeNode* root, int high){
        if(root == NULL || root->right == NULL){
            return;
        }
        while(root->right != NULL && root->right->val > high){
            TreeNode* temp = root->right->left;
            root->right = temp;
        }
        
        right_trim(root->right, high);
    }
    TreeNode* find_root(TreeNode* root, int low, int high){
        if(root == NULL){
            return NULL;
        }
        TreeNode* res = root;
        if(root->val < low){
            res = find_root(root->right, low, high);
        }else if(root->val > high){
            res = find_root(root->left, low, high);
        }
        
        return res;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // root = find_root(root, low, high);
        // left_trim(root, low);
        // right_trim(root, high);
        
        if(root == NULL)    return NULL;
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};