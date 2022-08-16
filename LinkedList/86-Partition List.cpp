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
    ListNode* partition(ListNode* head, int x) {
        ListNode *edge = NULL;
        ListNode* p = head;
        ListNode* pre = NULL;
        while(p!=NULL){
            if(p->val<x){
                if(pre == NULL){
                    edge = p;
                }else{
                    if(edge && edge->next == p){
                        edge = p;
                    }else{
                        pre->next = p->next;
                        if(edge == NULL){
                            p->next = head;
                            head = p;
                            edge = p;
                        }else{
                            p->next = edge->next;
                            edge->next = p;
                            edge = edge->next;
                        }
                        p = pre;
                    }
                }
            }
            if(p!=pre)  pre = p;
            p = p->next;
        }
        return head;
    }
};