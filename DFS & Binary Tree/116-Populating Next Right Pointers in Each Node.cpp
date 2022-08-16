/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> buffer;
        if(root == NULL){
            return root;
        }
        buffer.push(root);
        while(!buffer.empty()){
            int size = buffer.size();
            while(size!=0){
                size--;
                Node* node = buffer.front();
                buffer.pop();
                if(size!=0){
                    node->next = buffer.front();
                }
                if(node->left)  buffer.push(node->left);
                if(node->right) buffer.push(node->right);
            }
        }
        return root;
    }
};

class Solution {
public:
    void getNode(vector<Node*> buffer){
        if(buffer.size() == 0)  return;
        vector<Node*> buffer_child;
        for(int i=0;i<buffer.size()-1;i++){
            if(buffer[i]->left) buffer_child.push_back(buffer[i]->left);
            if(buffer[i]->right) buffer_child.push_back(buffer[i]->right);
            buffer[i]->next = buffer[i+1];
        }
        if(buffer.back()->left) buffer_child.push_back(buffer.back()->left);
        if(buffer.back()->right)    buffer_child.push_back(buffer.back()->right);
        getNode(buffer_child);
        
    }
    Node* connect(Node* root) {
        if(root == NULL)    return root;
        vector<Node*> buffer;
        buffer.push_back(root);
        getNode(buffer);
        
        return root;
    }
};