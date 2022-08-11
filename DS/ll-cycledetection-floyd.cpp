Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again 
by continuously following the next pointer. Internally,
 pos is used to denote the index of the node that tails next pointer is connected to. 
 ----> Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.


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
    //this is flyod's loop detection algorithm
    //this is also called as hare - tortoise problem as it uses 2 pointers, slow & fast
    //the key is slow ptr moves one by one and fast ptr moves twice so at one point if theres a loop they have to meet ie) fast will meet slow at some point which is when we return true
    // so the space complexity is O(1) and the time complexity is O(n) where n-ll size 
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
    if(slow==fast) return true;
        }
        return false;
    }
};