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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* LCA = NULL;
    bool compare_node(TreeNode* p, TreeNode* q){
        return p->val == q->val;
    }
    bool DFS(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return false;
        }
        bool left = DFS(root->left,p,q);
        bool right = DFS(root->right,p,q);
        if(left && right){
            LCA = root;
            return true;
        }
        if((compare_node(root,p) || compare_node(root,q)) && 
           (left || right)){
            LCA = root;
            return true;
        }
        if(compare_node(root,p) || compare_node(root,q) || left || right){
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root,p,q);
        return LCA;
        
    }
};

class Solution2 {
public:
    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){
        if(node == NULL){
            return false;
        }
        path.push_back(node);
        if(node == target){
            return true;
        }
        if(dfs(node->left, target, path) || dfs(node->right, target, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        vector<TreeNode*> p_path,q_path;
        if(!dfs(root, p, p_path) || !dfs(root, q, q_path)){
            return NULL;
        }
        int size = min(p_path.size(), q_path.size());
        TreeNode* LCA;
        for(int i=0;i<size;i++){
            if(p_path[i] != q_path[i]){
                break;
            }
            LCA = p_path[i];
        }
        return LCA;
        
    }
};

class Solution3 {
public:
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL){
            return NULL;
        }
        if(node == p || node == q){
            return node;
        }
        TreeNode* left= dfs(node->left, p,q);
        TreeNode* right = dfs(node->right, p,q);
        if(left && right){
            return node;
        }
        return left == NULL ? right : left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};