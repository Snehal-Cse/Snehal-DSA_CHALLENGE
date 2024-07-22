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
    ListNode *curr = head;
    ListNode *prev= NULL;
    ListNode *currNext= NULL;    
        while(curr!=NULL){
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr= currNext;
        }
        return prev;

    }
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
      ListNode *temp1 = head;
      ListNode *mid = findMid(head);
      ListNode *nextNode = mid->next;
      mid->next = NULL;
      ListNode *temp2 = reverseList(nextNode);
      while(temp2!=NULL){
          ListNode *ptr1 = temp1->next;
          ListNode *ptr2 = temp2->next;
          temp1->next = temp2;
         
          temp2->next = ptr1;
          temp1 = ptr1;
          temp2 = ptr2;
          
      }
        
        
       
        
    }
};