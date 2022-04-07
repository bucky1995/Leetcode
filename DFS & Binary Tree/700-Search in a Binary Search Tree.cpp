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
    
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*> buffer;
        if(root->val == val){
            return root;
        }
        
        buffer.push_back(root);
        
        while(!buffer.empty()){
            int row_size = buffer.size();
            for(int i=0;i<row_size;i++){
                TreeNode* node = buffer.front();
                buffer.erase(buffer.begin());

                if(node->val == val){
                    return node;
                }

                if(node->left != NULL) buffer.push_back(node->left);
                if(node->right != NULL) buffer.push_back(node->right);
            }
        }
        
        return NULL;
    }
};