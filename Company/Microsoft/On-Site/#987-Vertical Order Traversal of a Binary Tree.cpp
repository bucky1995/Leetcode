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
    int most_left;
    int most_right;
    unordered_map<int, vector<vector<int>>> buffer;
    void dfs(TreeNode* root, int col, int level){
        if(root ==NULL) return;
        if(col<most_left)   most_left = col;
        if(col>most_right)  most_right = col;
        
        buffer[col].push_back({root->val, level});
        dfs(root->right, col+1, level+1);
        dfs(root->left, col-1, level+1);
        
    }
    static bool compare(vector<int> a, vector<int> b){
        return a.back() < b.back();
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(int i=most_left; i<=most_right;i++){
            vector<vector<int>> temp1 = buffer[i];
            vector<int> temp2;
            unordered_map<int, vector<int>> level_buffer;
            vector<int> level;
            //sort(temp1.begin(), temp1.end(), compare);
            for(vector<int> item: temp1){
                if(level_buffer.count(item.back()) == 0)
                    level.push_back(item.back());
                level_buffer[item.back()].push_back(item.front());
            }
            sort(level.begin(), level.end());
            for(int l : level){
                vector<int> b = level_buffer[l];
                if(b.size() == 1){
                    temp2.push_back(b.front());
                }else{
                    sort(b.begin(), b.end());
                    for(int val : b){
                        temp2.push_back(val);
                    }
                }
            }
            
            res.push_back(temp2);
        }
        return res;
    }
};