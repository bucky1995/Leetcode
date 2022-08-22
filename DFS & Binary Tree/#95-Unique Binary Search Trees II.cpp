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
    vector<TreeNode*> generate(int left, int right){
        vector<TreeNode*> res;
        if(left>right){
            res.push_back(NULL);
            return res;
        }
        
        for(int i=left;i<=right;i++){
            vector<TreeNode*> lefts = generate(left, i-1);
            vector<TreeNode*> rights = generate(i+1, right);
            
            for(TreeNode* left : lefts){
                for(TreeNode* right : rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return vector<TreeNode*>{NULL};
        return generate(1,n);
    }
};