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
    vector<int> buffer;
    double min_dis = INT_MAX;
    int min_index = -1;
    void get_node(TreeNode* node, int target){
        if(node == NULL)    return;
        get_node(node->left, target);
        
        buffer.push_back(node->val);
        
        get_node(node->right, target);
        
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        get_node(root, target);
        
        int min_index = 0;
        
        for(int i=1;i<buffer.size();i++){
            if(abs(target - buffer[min_index]) > abs(buffer[i] - target)){
                min_index = i;
            }
        }
        int left = min_index - 1;
        int right = min_index + 1;
        
        vector<int> res;
        
        res.push_back(buffer[min_index]);
        k--;
        while(k!=0){
            if(left>=0 && right<buffer.size()){
                if(abs(buffer[left] - target) > abs(buffer[right] - target)){
                    res.push_back(buffer[right]);
                    right++;
                }else{
                    res.push_back(buffer[left]);
                    left--;
                }   
                k--;
            }
            
            else if(left>=0){
                while(k!=0){
                    res.push_back(buffer[left]);
                    left--;
                    k--;
                }
                break;
            }
            else if(right<buffer.size()){
                while(k!=0){
                    res.push_back(buffer[right]);
                    right++;
                    k--;
                }
                break;
            }
        }
        
        return res;
    }
};