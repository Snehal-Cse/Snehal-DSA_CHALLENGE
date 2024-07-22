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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *firstLink = reverseList(l1);
       ListNode *secondLink = reverseList(l2);
       ListNode *ptr1 = firstLink;
       ListNode *ptr2 = secondLink;
        int carry = 0;
        int sum =0;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *dummyTail = dummyNode;
       while(ptr1!=NULL || ptr2!=NULL){
           sum = carry;
           if(ptr1!=NULL){
               sum+=ptr1->val;
               ptr1 = ptr1->next;
           }
           if(ptr2!=NULL){
                sum+=ptr2->val;
               ptr2 = ptr2->next;
           }
           carry = sum/10;
           dummyTail->next = new ListNode(sum%10);
           dummyTail = dummyTail->next;
       }
        if(carry){
            dummyTail->next = new ListNode(1);
            dummyTail = dummyTail->next;
        }
       ListNode *ans = reverseList(dummyNode->next);
        return ans;
        
        
    }
};