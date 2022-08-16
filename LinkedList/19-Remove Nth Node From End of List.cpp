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
    int sum;
    bool dfsDel(ListNode* p, int n){
        if(p == NULL){
            return false;
        }
        bool del = dfsDel(p->next, n);
        sum++;
        if(sum == n){
            return true;
        }
        if(del){
            p->next = p->next->next;
        }
        return false;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        sum = 0;
        if(dfsDel(head, n)){
            head = head->next;
        }
        return head;
    }
};