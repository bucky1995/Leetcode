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
    int res;
    long target;
    void dfs(TreeNode* root, vector<long> buffer){
        if(root == NULL)    return;
        long num = root->val;
        buffer.push_back(0);
        for(int i=0;i<buffer.size();i++){
            buffer[i] += num;
            if(buffer[i] == target)
                res++;
        }
        dfs(root->left, buffer);
        dfs(root->right, buffer);
    }
    int pathSum(TreeNode* root, int targetSum) {
        res = 0;
        target = targetSum;
        dfs(root, {});
        return res;
    }
};