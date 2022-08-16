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
    int cur;
    bool stop;
    int res;
    void inTravel(TreeNode* root, int k){
        if(root == NULL){
            return;
        }
        inTravel(root->left,k);
        if(stop)    return;
        cur++;
        if(cur == k){
            stop = true;
            res = root->val;
            return;
        }
        inTravel(root->right,k);        
    }
    int kthSmallest(TreeNode* root, int k) {
        cur = 0;
        stop = false;
        inTravel(root, k);
        return res;
    }
};