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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0){
            return NULL;
        }
        int root_val = preorder.front();
        TreeNode* root = new TreeNode(root_val);
        preorder.erase(preorder.begin());
        int i=0;
        while(inorder[i]!=root_val){
            i++;
        }

        vector<int> left_inorder = vector<int> (inorder.begin(), inorder.begin()+i);
        vector<int> right_inorder = vector<int> (inorder.begin()+i+1, inorder.end());

        root->left = buildTree(preorder, left_inorder);
        root->right = buildTree(preorder, right_inorder);

        return root;
    }
};