#include <iostream> 
#include <unordered_map> 
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    unordered_map<int,vector<int>> hash;
    int left=0,right=0;
    
    void  verticalTravel(TreeNode* root){
        vector<TreeNode*> bfs;
        vector<int> bfs_col;
        bfs.push_back(root);
        bfs_col.push_back(0);
        
        //BFS travel start from here
        while(!bfs.empty()){
            TreeNode *cur = bfs.front();
            int col = bfs_col.front();
            
            if(col<left) left=col;
            if(col>right) right = col;
        
            bfs.erase(bfs.begin());
            bfs_col.erase(bfs_col.begin());
            
            if(cur->left) {
                bfs.push_back(cur->left);
                bfs_col.push_back(col-1);
            }
            if(cur->right){
                bfs.push_back(cur->right);
                bfs_col.push_back(col+1);
            } 
            
            hash[col].push_back(cur->val);
        }
        //end here
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        verticalTravel(root);
        for(int i=left;i<=right;i++){
            res.push_back(hash[i]);
        }
        return res;
    }
};