/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *travelDis(ListNode* head, int n){
        while(n!=0){
            head = head->next;
            n--;
        }
        return head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        int l1 = 0;
        int l2 = 0;
        
        while(p!=NULL || q!=NULL){
            if(p!=NULL){
                l1++;
                p = p->next;
            }
            if(q!=NULL){
                l2++;
                q=q->next;
            }
        }
        p = headA;
        q = headB;
        
        int len = max(l1, l2);
        int dis = len - min(l1,l2);
        
        if(l1>l2){
            p = travelDis(p, dis);
        }else if(l1<l2){
            q = travelDis(q, dis);
        }
        while(p!=NULL){
            if(p == q)  return q;
            p = p->next;
            q = q->next;
        }
        
        return NULL;
    }
};