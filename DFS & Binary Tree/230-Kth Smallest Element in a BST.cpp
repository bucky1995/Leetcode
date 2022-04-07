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
    bool find = false;
    int ks;
    int cur_k = 0;
    void travel(TreeNode* root, int k){
        if(root == NULL){
            return;
        }
        travel(root->left,k);
        cur_k++;
        if(cur_k == k){
            ks = root->val;
            find = true;
        }
        if(find){
            return;
        }
        travel(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //travel(root, k);
        //return ks;
        
        vector<TreeNode*> buffer;
        TreeNode* node = root;
        while(node!=NULL){
            buffer.push_back(node);
            node = node->left;
        }
        
        for(int i=0;i<k-1;i++){
            TreeNode* temp = buffer.back();
            buffer.pop_back();
            if(temp->right!= NULL){
                temp = temp->right;
                while(temp!=NULL){
                    buffer.push_back(temp);
                    temp = temp->left;
                }
            }
        }
        
        return buffer.back()->val;
    }
};