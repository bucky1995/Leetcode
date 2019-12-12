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
    void flatten(TreeNode* root) {
        TreeNode* d = new TreeNode(0); 
        preorder(root, d);
        delete d;
    }
    
private:
    void preorder(TreeNode* const c, TreeNode* p) {
        p->right = c;
        
        if (c == NULL)
            return;

        TreeNode* temp = c->right;
        p->left = NULL;
        
        preorder(c->left, c);
        
        while(p->right)
            p = p->right;

        preorder(temp, p);   
    }
};