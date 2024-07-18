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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *dummyHead = new ListNode(-1);
      ListNode *dummyTail = dummyHead;
      ListNode *curr1 = l1;
      ListNode *curr2 = l2;
        int carry =0;
      while(curr1 != NULL && curr2 != NULL){
          int sum = curr1->val + curr2->val +carry;
          carry = sum/10;
          int newsum = sum%10;
          ListNode *addNode = new ListNode(newsum);
          dummyTail ->next = addNode;
          dummyTail = addNode;
          carry = sum/10;
          curr1 = curr1->next;
          curr2 = curr2->next;
      }
        while(curr1 !=NULL){
            int sum = curr1->val + carry;
          int newsum = sum%10;
          ListNode *addNode = new ListNode(newsum);
          dummyTail ->next = addNode;
          dummyTail = addNode;
          carry = sum/10;
          curr1 = curr1->next;
        }
          while(curr2 !=NULL){
            int sum = curr2->val + carry;
          int newsum = sum%10;
          ListNode *addNode = new ListNode(newsum);
          dummyTail ->next = addNode;
          dummyTail = addNode;
          carry = sum/10;
          curr2 = curr2->next;
        }
        if(carry!=0){
            ListNode *addNode = new ListNode(carry);
          dummyTail ->next = addNode;
          dummyTail = addNode;
        }
        dummyTail->next = NULL;
        return dummyHead->next;
        
    }
};