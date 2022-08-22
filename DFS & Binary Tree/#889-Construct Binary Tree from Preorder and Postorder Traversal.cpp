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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        postorder.pop_back();
        
        if(preorder.size() == 0){
            return root;
        }
        
        int left_len = 0;
        while(preorder[left_len]!=postorder.back()){
            left_len++;
        }
        int right_len = preorder.size() - left_len;
        vector<int> left_pre = vector<int>(preorder.begin(), preorder.begin()+left_len);
        vector<int> left_post = vector<int>(postorder.begin(), postorder.begin()+left_len);
        vector<int> right_pre = vector<int>(preorder.begin()+left_len, preorder.end());
        vector<int> right_post = vector<int>(postorder.begin()+left_len, postorder.end());
        
        root->left = constructFromPrePost(left_pre, left_post);
        root->right = constructFromPrePost(right_pre, right_post);
        return root;
        
    }
};