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
    void sumTree(TreeNode* root,int &sum){
        if(root==NULL){
            return;
        }
        sumTree(root->right,sum);
        sum=sum+root->val;
        root->val=sum;
        sumTree(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        sumTree(root,sum);
        return root;
    }

    TreeNode* Find(TreeNode* root, TreeNode* p,TreeNode* min){
        if(root==NULL) return min;
        if(root->val > p->val){
            if(min!=NULL){
                min=root->val-p->val < min->val-p->val ? root:min;
            }else{
                min=root;
            }
        }
        if(root->val<=p->val){
            min = Find(root->right,p,min);
        }else if(root->val>p->val){
            min = Find(root->left,p,min);
        }
        return min;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* min=NULL;
        min = Find(root,p,min);
        return min;
    }

    TreeNode* travelLR(TreeNode* root){
        TreeNode* newroot;
        if(root->left!=NULL){
            newroot=travelLR(root->left);
            root->left->left=root->right;
            root->left->right=root;
            root->right=NULL;//对于建树没什么影响，但是当打印的时候会出现死循环，起到清理原来树的作用，非常重要，死循环出现在打印步骤
            root->left=NULL;
        }else{
            newroot=root;
        }
        return newroot;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* newroot=travelLR(root);
        return newroot;
    }

    int collectLeaves(TreeNode* root,vector<vector<int>> &res){
        if(root==NULL) return 0;

        int leftDepth=collectLeaves(root->left,res);
        int rightDepth=collectLeaves(root->right,res);

        int depth = (leftDepth>rightDepth?leftDepth:rightDepth) +1 ;

        if(depth>res.size()){
            res.push_back(vector<int> ());
        }

        res[depth-1].push_back(root->val);
        return depth;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {//只要找到每个节点的从叶子节点起算的深度
        vector<vector<int>> res;
        collectLeaves(root,res);
        return res;
    }

    unordered_map<int,vector<int>> hash;
    int left=0,right=0;
    void  verticalTravel(TreeNode* root){
        vector<TreeNode*> bfs;
        vector<int> bfs_col;
        bfs.push_back(root);
        bfs_col.push_back(0);
        
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