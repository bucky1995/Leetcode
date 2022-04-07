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
    double dis(int a, double target){
        return abs(a-target);
    }
    
    int travel(TreeNode* root, double target){
        int closest = root->val;
        while(root!=NULL){
            closest = abs(closest - target) > abs(root->val - target) ? root->val : closest;
            
            if(target>root->val)    root = root->right;
            else    root = root->left;
        }
        return closest;
    }
    
    int closestValue(TreeNode* root, double target) {
        if(!root)   return -1;
        return travel(root, target);
    }
};