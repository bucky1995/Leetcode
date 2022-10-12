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
    //{l, h, sum, isbst}
    int res;
    vector<int> dfs(TreeNode* root){
        if(root == NULL){
            return {INT_MAX, INT_MIN, 0, 1};
        }
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        int sum = root->val + left[2] + right[2];
        int isbst = 0;
        if(left[3] == 1 && right[3] == 1 && root->val <right[0] && root->val >left[1]){
            res = max(sum, res);
            isbst = 1;
        }
        
        int l = min(root->val, left[0]);
        int h = max(root->val, right[1]);
        
        return {l, h, sum, isbst};
    }
    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};