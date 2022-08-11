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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode* p = head;
        while(p->next){
            if(p->next->val==val){
                ListNode* q=p->next->next;
                delete(p->next);
                p->next=q;
            }
            else 
                p=p->next;
        }
         if(head->val==val) { head=head->next; }
        return head;
    }
};