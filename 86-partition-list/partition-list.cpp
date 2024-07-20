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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *dummyTail = dummyNode;
         ListNode *NextNode = new ListNode(-1);
        ListNode *NextTail = NextNode;
        ListNode *ptr = head;
        while(ptr!=NULL){
            if(ptr->val < x ){
                dummyTail->next = ptr;
                dummyTail = dummyTail->next;
                ptr = ptr->next; 
            }
            else{
                NextTail->next = ptr;
                NextTail = NextTail->next;
                ptr= ptr->next;
            }
        }
        
      dummyTail->next = NextNode->next;
      
        NextTail->next = NULL;
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *dummyTail = dummyNode;
         ListNode *NextNode = new ListNode(-1);
        ListNode *NextTail = NextNode;
        ListNode *ptr = head;
        while(ptr!=NULL){
            if(ptr->val < x ){
                dummyTail->next = ptr;
                dummyTail = dummyTail->next;
                ptr = ptr->next; 
            }
            else{
                NextTail->next = ptr;
                NextTail = NextTail->next;
                ptr= ptr->next;
            }
        }
        
      dummyTail->next = NextNode->next;
       
        NextTail->next = NULL;
         delete(NextNode);
        return dummyNode ->next;
        
        
    }
};
        return dummyNode ->next;
        
        
    }
};