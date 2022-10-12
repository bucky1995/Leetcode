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
    unordered_map<int, vector<vector<int>>> cache;
    int left_most;
    int right_most;
    static bool compare(vector<int> a, vector<int> b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1]<b[1];
    }
    void dfs(TreeNode* root, int col, int level){
        if(root == NULL){
            return;
        }
        
        if(left_most>col)
            left_most = col;
        if(right_most<col)
            right_most = col;
        cache[col].push_back({root->val, level});
        
        dfs(root->left, col-1, level+1);
        dfs(root->right, col+1, level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        left_most = 0;
        right_most = 0;
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(int i=left_most;i<=right_most;i++){
            vector<vector<int>> temp = cache[i];
            sort(temp.begin(), temp.end(), compare);
            vector<int> level;
            for(vector<int> item : temp){
                level.push_back(item[0]);
            }
            res.push_back(level);
        }
        return res;
    }
};