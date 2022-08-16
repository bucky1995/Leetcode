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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return NULL;
        }
        
        int root_val = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(root_val);
        
        int i=0;
        while(inorder[i] != root_val){
            i++;
        }

        vector<int> left = vector<int> (inorder.begin(), inorder.begin()+i);
        vector<int> right = vector<int> (inorder.begin()+i+1, inorder.end());
        
        root->right = buildTree(right, postorder);
        root->left = buildTree(left, postorder);
        return root;
    }
};