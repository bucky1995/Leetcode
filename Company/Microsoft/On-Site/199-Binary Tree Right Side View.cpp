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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> buffer;
        vector<int> res;
        if(root == NULL)    return res;
        buffer.push(root);
        while(!buffer.empty()){
            int len = buffer.size();
            vector<int> level_val;
            for(int i=0;i<len;i++){
                TreeNode* node = buffer.front();
                buffer.pop();
                level_val.push_back(node->val);
                if(node->left)  buffer.push(node->left);
                if(node->right) buffer.push(node->right);
            }
            res.push_back(level_val.back());
        }
        return res;
    }
};