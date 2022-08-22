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
    
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* p = head;
        while(p){
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        return pre;
    }
};