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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)    return head;
        unordered_set<int> hash;
        ListNode* p = head->next;
        ListNode* q = head;
        hash.insert(q->val);
        while(p!=NULL){
            int num = p->val;
            if(hash.find(num)!=hash.end()){
               q->next = p->next;
            }else{
                hash.insert(num);
                q=p;
            }
            p=p->next;
        }
        return head;
    }
};