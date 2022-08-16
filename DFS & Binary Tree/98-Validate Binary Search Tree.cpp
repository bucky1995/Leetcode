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
    bool validate(TreeNode* root, long min, long max){
        if(root == NULL)    return true;
        int num = root->val;
        if(num>=max || num<=min)  return false;
        
        return validate(root->left, min, num) && validate(root->right, num, max);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root->left, LONG_MIN, root->val) && validate(root->right, root->val, LONG_MAX);
    }
};