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
    void bfs(vector<TreeNode*> nodes){
        if(nodes.size() == 0)   return;
        vector<TreeNode*> next_level;
        vector<int> buffer;
        for(TreeNode* node : nodes){
            buffer.push_back(node->val);
            if(node->left)  next_level.push_back(node->left);
            if(node->right) next_level.push_back(node->right);
        }
        bfs(next_level);
        res.push_back(buffer);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)    return res;
        vector<TreeNode*> buffer;
        buffer.push_back(root);
        bfs(buffer);
        return res;
    }
};