#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    vector<Node*> BFS_scan(Node * node){
        vector<Node*> res;
        vector<Node*> buffer;
        unordered_set<Node*> visited;
        res.push_back(node);
        buffer = node->neighbors;
        visited.insert(node);
        
        while(!buffer.empty()){
            Node* cur = buffer.front();
            buffer.erase(buffer.begin());
            res.push_back(cur);
            visited.insert(cur);
            for(int i=0;i<cur->neighbors.size();i++){
                Node* neighbor = cur->neighbors[i];
                if(visited.find(neighbor) != visited.end()){
                    continue;
                }
                buffer.push_back(neighbor);
            }
        }
        
        return res;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        vector<Node*> nodes = BFS_scan(node);
        
        unordered_map<Node*, int> hash;
        for(int i=0;i<nodes.size();i++){
            hash[nodes[i]] = i;
        }
        
        vector<Node*> buffer;
        
        for(int i=0;i<nodes.size();i++){
            Node* cur = new Node(nodes[i]->val);
            buffer.push_back(cur);
        }
        
        for(int i=0;i<nodes.size();i++){
            vector<Node*> temp;
            vector<Node*> old_neighbors = nodes[i]->neighbors;
            for(int j=0;j<old_neighbors.size();j++){
                temp.push_back(buffer[
                    hash[
                        old_neighbors[j]
                    ]
                ]);
            }
            buffer[i]->neighbors = temp;
        }
        
        return buffer.front();
    }
};