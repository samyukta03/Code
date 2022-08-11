Given the head of a singly linked list, return true if it is a palindrome.

 /*------Naive/ Brute force approach -------- */
 //Basically push the ll elements to an array and then check the array is a reverse of itself using 
 //two ptrs one frm the beginning and the other from the end and inc&dec them
   bool revarray(vector<int>& list){
      int i=0,j=list.size()-1;
      while(i<=j){
          if(list[i]!=list[j]) return false;
          i++;
          j--;
      }
      return true;  
  }
    bool isPalindrome(ListNode* head) {
        vector<int> l;
       while(head!=NULL){
           l.push_back(head->val);
           head=head->next;
       }
        return revarray(l);
    }
/*-------------optimized approach--------------*/
