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
    int sum;
    void inTravel(TreeNode* root){
        if(root == NULL)    return;
        inTravel(root->right);
        root->val += sum;
        sum=root->val;
        inTravel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)    return root;
        sum = 0;
        inTravel(root);
        return root;
    }
};