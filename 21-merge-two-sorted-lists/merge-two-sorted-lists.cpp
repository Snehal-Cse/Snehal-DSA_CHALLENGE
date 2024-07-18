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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        while(curr1 !=NULL && curr2 !=NULL){
            if(curr1->val <= curr2->val){
                dummyTail->next = curr1;
                dummyTail = dummyTail->next;
                curr1 = curr1->next;
            }
            else{
                dummyTail->next = curr2;
                dummyTail = dummyTail->next;
                curr2 = curr2->next;
            }
        }
        while(curr1!=NULL){
            dummyTail->next = curr1;
             dummyTail = dummyTail->next;
                curr1 = curr1->next;
            
        }
        while(curr2!=NULL){
            dummyTail->next = curr2;
             dummyTail = dummyTail->next;
                curr2 = curr2->next;
            
        }
        dummyTail->next = NULL;
        return dummyHead->next;
    }
};