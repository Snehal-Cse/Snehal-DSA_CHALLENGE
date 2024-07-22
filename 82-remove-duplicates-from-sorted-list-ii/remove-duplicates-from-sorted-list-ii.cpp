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
      ListNode *ptr1 = head;
        if(head == NULL || head->next == NULL){
            return head;
        }
      ListNode *ptr2 = head->next;
      ListNode *dummy = new ListNode(-1);
        dummy->next= head;
        ListNode *prev = dummy;
      while(ptr2!=NULL){
          if(ptr1->val != ptr2->val){
              ptr1 = ptr1->next;
              ptr2= ptr2 ->next;
              prev = prev->next;
          }
          else{
             while(ptr2 !=NULL && ptr1->val == ptr2->val){
                 ptr2= ptr2->next;
             }
              prev ->next = ptr2;
              ptr1 = ptr2;
             if(ptr1!=NULL){
                 ptr2 = ptr1->next;
             }
          }
      }
        return dummy->next;
        
    }
};