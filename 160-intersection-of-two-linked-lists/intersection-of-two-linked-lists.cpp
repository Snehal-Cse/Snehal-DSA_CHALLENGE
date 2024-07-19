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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *ptr1 = headA;
         ListNode *ptr2 = headB;
       if(headA==NULL || headB ==NULL){
           return NULL;
       }
        int cnt1=0;
        int cnt2 =0;
        while(ptr1!=NULL){
            cnt1++;
            ptr1= ptr1->next;
        }
         while(ptr2!=NULL){
            cnt2++;
            ptr2= ptr2->next;
        }
        int diff = abs(cnt2-cnt1);
        ptr1 = headA;
       ptr2 = headB;
     if(cnt1>cnt2){
         while(diff){
             ptr1 = ptr1->next;
             diff--;
         }
     }
        else{
           while(diff){
             ptr2 = ptr2->next;
             diff--;
         } 
        }
      while(ptr1!=NULL && ptr2!=NULL){
       
          if(ptr1 == ptr2){
              return ptr1;
          }
           ptr1 =  ptr1->next;
          ptr2 = ptr2 ->next;
      }  
        
        return NULL;
        
        
        
        
    }
};