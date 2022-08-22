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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;
        
        ListNode* res_head = NULL;
        ListNode* res = NULL;
        while(p!=NULL && q!=NULL){
            ListNode* min_node;
            if(p->val < q->val){
                min_node = p;
                p=p->next;
            }else{
                min_node = q;
                q=q->next;
            }
            
            if(res == NULL){
                res = min_node;
                res_head = res;
            }else{
                res->next = min_node;
                res = res->next;
            }
            res->next = NULL;
            
        }
        if(p!=NULL || q!=NULL){
            if(res == NULL)
                res_head = p == NULL?q:p;
            else
                res->next = p == NULL?q:p;
        }
        return res_head;
    }
};