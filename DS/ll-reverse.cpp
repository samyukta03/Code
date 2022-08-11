
class Solution{
  public:
  ListNode* reverselist(ListNode* head){
    if(!head || head->next == NULL) return head;
    ListNode* curr=head;
    ListNode *prev,*nxt=NULL;
    while(head){
      nxt=curr->next;
      curr->next=prev;
      prev=curr;
      curr->next=nxt;
    }
    return head;
  }
}