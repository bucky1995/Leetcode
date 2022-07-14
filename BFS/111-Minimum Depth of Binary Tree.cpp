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
    int minDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        queue<TreeNode*> buffer;
        buffer.push(root);
        int level = 0;
        while(!buffer.empty()){
            int n = buffer.size();
            TreeNode* cur;
            level++;
            for(int i=0;i<n;i++){
                cur = buffer.front();
                buffer.pop();
                if(cur->left == NULL && cur->right == NULL)  return level;
                if(cur->left)   buffer.push(cur->left);
                if(cur->right)  buffer.push(cur->right);
            }
        }
        return level;
    }
};