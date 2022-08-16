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
    int find_max(vector<int> nums){
        int max = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[max]){
                max = i;
            }
        }
        return max;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
             return NULL;
        }
        
        int max_index = find_max(nums);
        
        TreeNode* res = new TreeNode(nums[max_index]);
        vector<int> left(nums.begin(), nums.begin()+max_index);
        vector<int> right(nums.begin()+max_index+1, nums.end());
        
        res->left = constructMaximumBinaryTree(left);
        res->right = constructMaximumBinaryTree(right);
        
        return res;
    }
};