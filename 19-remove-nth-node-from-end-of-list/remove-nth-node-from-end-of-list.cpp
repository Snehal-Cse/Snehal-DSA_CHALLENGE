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
       ListNode *ptr2 = ptr->next;
        int i =1;
       
        while(i<n-1){
            ptr= ptr->next;
            ptr2= ptr2->next;
            i++;
        }
        if(ptr!=NULL && ptr2!=NULL){
             ptr->next = ptr2->next;
        }
       
      
      ListNode *newNode = reverseList(temp);
        return newNode;


    }
};