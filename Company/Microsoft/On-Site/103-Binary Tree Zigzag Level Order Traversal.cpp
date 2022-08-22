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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag = true;//false: right->left, true: left->right
        vector<TreeNode*> buffer;
        vector<vector<int>> res;
        if(root == NULL)    return res;
        buffer.push_back(root);
        
        while(!buffer.empty()){
            vector<int> level_val;
            
            int len = buffer.size();
            vector<TreeNode*> next;
            
            for(int i=0;i<len;i++){
                TreeNode* node = buffer[i];
                if(node->left)  next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            
            if(flag){
                for(int i=0;i<len;i++){
                    TreeNode* node = buffer[i];
                    level_val.push_back(node->val);
                }
            }else if(!flag){
                for(int i=len-1;i>=0;i--){
                    TreeNode* node = buffer[i];
                    level_val.push_back(node->val);
                }
            }
            res.push_back(level_val);
            buffer=next;
            flag = !flag;
            
        }
        return res;
    }
};