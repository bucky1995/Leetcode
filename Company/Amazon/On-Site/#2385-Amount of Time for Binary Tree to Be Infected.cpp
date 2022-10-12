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
    unordered_map<int, unordered_set<int>> g;
    int res;
    void generateG(TreeNode* root){
        if(root == NULL)
            return;
        if(root->left){
            g[root->val].insert(root->left->val);
            g[root->left->val].insert(root->val);
        }
        if(root->right){
            g[root->val].insert(root->right->val);
            g[root->right->val].insert(root->val);
        }
        
        generateG(root->left);
        generateG(root->right);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        generateG(root);
        
        queue<pair<int, int>> buffer;
        
        buffer.push({start, 0});
        int res = 0;
        
        while(!buffer.empty()){
            pair<int,int> q = buffer.front();
            int cur_step = q.second;
            int cur_num = q.first;
            buffer.pop();
            unordered_set<int> next_points = g[cur_num];
            for(int next: next_points){
                if(g.count(next)!=0){
                    buffer.push({next, cur_step+1});
                }
            }
            res = max(res, cur_step);
            g.erase(cur_num);
        }
        return res;
    }
};