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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)   return head;
        ListNode* p=head;
        ListNode* p_pre = NULL;
        int i=1;
        while(i!=left){
            p_pre = p;
            p=p->next;
            i++;
        }
        ListNode* q=p;
        ListNode* q_next;
        while(i!=right){
            q=q->next;
            q_next = q->next;
            i++;
        }
        
        vector<ListNode*> buffer;
        ListNode* node = p;
        while(node!=q){
            buffer.push_back(node);
            node = node->next;
        }
        buffer.push_back(q);
        
        for(i = buffer.size()-1;i>0;i--){
            buffer[i]->next = buffer[i-1];
        }
        
        if(p_pre){
            p_pre->next = buffer.back();
        }
        
        buffer.front()->next = q_next;
        if(left!=1) return head;
        else    return buffer.back();
    }
};