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
    ListNode *merge(ListNode *left, ListNode *right){
         ListNode *dummyNode = new ListNode(-1);
        ListNode *dummyTail = dummyNode;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                dummyTail->next = left;
                left = left ->next;
            }
            else{
                dummyTail->next= right;
                right= right->next;
            }
            dummyTail = dummyTail->next;
            
        }
        while(left!=NULL){
            dummyTail ->next = left;
             left = left ->next;
            dummyTail = dummyTail->next;
        }
        while(right!=NULL){
            dummyTail->next = right;
             right= right->next;
             dummyTail = dummyTail->next;
            
        }
        dummyTail ->next = NULL;
        return dummyNode->next;
        
        
        
        
        
    }
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head){
        if(head ==NULL || head->next ==NULL){
            return head;
        }
         ListNode * midNode = findMid(head);
         ListNode *nextNode = midNode->next;
         midNode->next = NULL;
         ListNode *left = sortList(head);
         ListNode *right = sortList(nextNode);
        return merge(left, right);
      
    }
};
