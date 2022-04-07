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
    double dis(TreeNode* node, double a){
        return abs(node->val - a);
    }
    
    TreeNode* find_lower(TreeNode* root, double target){
        if(root == NULL){
            return NULL;
        }
        
        if(root->val > target){
            return find_lower(root->left,target);
        }
        
        TreeNode* lower = find_lower(root->right, target);
        return lower == NULL ? root: lower;
    }
    
    TreeNode* find_upper(TreeNode* root, double target){
        if(root == NULL){
            return NULL;
        }
        
        if(root->val <= target){
            return find_upper(root->right, target);
        }
        
        TreeNode* upper = find_upper(root->left, target);
        return upper == NULL ? root: upper;
    }
    
    int closestValue(TreeNode* root, double target) {
        // TreeNode* node = root;
        // int res = root->val;
        // double min_dis = dis(root, target);
        // while(node!=NULL){
        //     double d = dis(node,target);
        //     if(min_dis > d){
        //         min_dis = d;
        //         res = node->val;
        //     }
        //     if(node->left && target<node->val){
        //         node = node->left;
        //     }else if(node->right && target>node->val){
        //         node = node->right;
        //     }else{
        //         break;
        //     }
        // }
        
        if(root == NULL){
            return 0;
        }
        
        TreeNode* lower = find_lower(root, target);
        TreeNode* upper = find_upper(root, target);
        
        if(lower == NULL){
            return upper->val;
        }
        if(upper == NULL){
            return lower->val;
        }
        
        return dis(lower, target) > dis(upper, target) ? upper->val:lower->val; 
        
        //return res;
        
    }
};