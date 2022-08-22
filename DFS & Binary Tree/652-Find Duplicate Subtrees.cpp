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
    unordered_set<string> visited;
    unordered_set<string> subTreeSet;
    vector<TreeNode*> res;
    string getSubTree(TreeNode* root){
        if(root == NULL)    return "#";
        string left = getSubTree(root->left);
        string right = getSubTree(root->right);
        
        string subTree = left + "," + right + "," + to_string(root->val);
        
        if(subTreeSet.count(subTree) && !visited.count(subTree)){
            res.push_back(root);
            visited.insert(subTree);
        }else{
            subTreeSet.insert(subTree);
        }
        return subTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getSubTree(root);
        return res;
    }
};