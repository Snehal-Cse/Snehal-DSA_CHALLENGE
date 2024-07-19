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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head == NULL ){
           return NULL;
       }
        int cnt=0;
        ListNode *t = head;
        while(t!=NULL){
            cnt++;
            t=t->next;
        }
        if(n>cnt){
            return head;
        }
       ListNode *temp = reverseList(head);
         if(n==1){
           return  reverseList(temp->next);
        }
     
        ListNode *ptr = temp;
        for (int i = 1; i < n - 1; i++) {
            ptr = ptr->next;
        }

        // Remove the nth node from the end
        if (ptr != NULL && ptr->next != NULL) {
            ptr->next = ptr->next->next;
        }
       
      
      ListNode *newNode = reverseList(temp);
        return newNode;


    }
};