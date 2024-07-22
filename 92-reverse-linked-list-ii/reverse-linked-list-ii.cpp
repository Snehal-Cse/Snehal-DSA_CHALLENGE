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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        if(head == NULL || head->next ==NULL || left == right ){
            return head;
        }
       ListNode *dummyNode = new ListNode(-1);
        ListNode *prev = dummyNode;
        dummyNode->next = head;
        for(int i=1;i<left;i++){
            prev= prev->next;
        }
        ListNode *reverseStart = prev->next;
        ListNode*reverseEnd = reverseStart;
        for(int i= left ; i<right;i++){
            reverseEnd = reverseEnd->next;
        }
        ListNode *nextNode = reverseEnd->next;
        reverseEnd->next = NULL;
        prev->next = reverseList(reverseStart);
        reverseStart->next= nextNode;
       return dummyNode->next; 
        
        
        
        
        
        
        
        
        
    }
};