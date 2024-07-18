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
    ListNode *reverse(ListNode *head){
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
   ListNode *mid(ListNode *head){
       ListNode *slow = head;
       ListNode *fast = head->next;
       while(fast!=NULL && fast->next !=NULL ){
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
   }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return true;
        }
       ListNode *midNode = mid(head);
       ListNode *temp = midNode ->next;  
        midNode ->next =NULL;
        ListNode *newHead = reverse(temp);
       
        
       
        ListNode *ptr = head;
        ListNode *ptr2 = newHead;
        while(ptr!=NULL && ptr2!=NULL){
            if(ptr->val !=ptr2->val){
                return false;
            }
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        
        return true;
        
        
      }
     
};