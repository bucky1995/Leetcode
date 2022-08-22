/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> buffer;
        ListNode* p = head;
        while(p!=NULL){
            buffer.push_back(p);
            p=p->next;
        }
        int i=0;
        vector<ListNode*> nodeList;
        while(i<buffer.size()/2){
            nodeList.push_back(buffer[i]);
            nodeList.push_back(buffer[buffer.size()-1-i]);
            i++;
        }
        if(buffer.size()%2 != 0){
            nodeList.push_back(buffer[i]);
        }
        for(i=0;i<nodeList.size()-1;i++){
            nodeList[i]->next = nodeList[i+1];
        }
        nodeList[i]->next = NULL;
    }
};