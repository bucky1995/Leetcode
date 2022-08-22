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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int targetSum, int curSum, vector<int> buffer){
        if(root == NULL)    return;
        curSum += root->val;
        buffer.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(curSum == targetSum){
                res.push_back(buffer);
            }
        }
        
        dfs(root->left, targetSum, curSum, buffer);
        dfs(root->right, targetSum, curSum, buffer);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0, {});
        return res;
    }
};