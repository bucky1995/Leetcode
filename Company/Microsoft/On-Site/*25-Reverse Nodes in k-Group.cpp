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
    int n;
    
    void reverse(ListNode* first, ListNode* last, ListNode* pre){
        ListNode* p = first;
        ListNode* tail = last->next;
        vector<ListNode*> buffer;
        while(p!=tail){
            buffer.push_back(p);
            p=p->next;
        }
        for(int i=buffer.size()-1;i>0;i--){
            buffer[i]->next = buffer[i-1];
        }
        buffer.front()->next = tail;
        if(pre!=NULL){
            pre->next = buffer.back();
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        n = 0;
        vector<ListNode*> buffer;
        while(p!=NULL){
            n++;
            buffer.push_back(p);
            p=p->next;
        }
        int group = n/k;
        p = head;
        int i=0;
        while(group!=0){
            group--;
            ListNode* first = buffer[i];
            ListNode* last = buffer[i+k-1];
            ListNode* pre = i == 0 ? NULL : buffer[i-k];
            reverse(first, last, pre);
            i = i+k;
        }
        return buffer[k-1];
    }
};