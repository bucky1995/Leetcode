#include <iostream> 
#include <unordered_set> 
#include <vector>
#include <string.h>
using namespace std;
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
    TreeNode* put_node(int left, int right, vector<int>& nums){
        if(left>right){
            return NULL;
        }
        
        int mid = left + (right - left)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = put_node(left,mid-1,nums);
        root->right = put_node(mid+1,right,nums);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return put_node(0,nums.size()-1,nums);
    }
};