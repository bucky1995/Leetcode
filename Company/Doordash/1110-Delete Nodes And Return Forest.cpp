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
    vector<TreeNode*> res;
    unordered_set<int> del;
    bool dfs(TreeNode* root){
        if(root == NULL)    return false;
        bool cut = false;
        if(del.count(root->val)!=0){
            if(root->left != NULL && del.count(root->left->val)==0)  res.push_back(root->left);
            if(root->right !=NULL && del.count(root->right->val)==0)  res.push_back(root->right);
            cut = true;
        }
        bool l = dfs(root->left);
        if(l)
            root->left = NULL;
        bool r = dfs(root->right);
        if(r)
            root->right = NULL;
        return cut;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL)    return res;
        del.insert(to_delete.begin(), to_delete.end());
        if(del.count(root->val)==0)
            res.push_back(root);
        dfs(root);
        return res;
    }
};