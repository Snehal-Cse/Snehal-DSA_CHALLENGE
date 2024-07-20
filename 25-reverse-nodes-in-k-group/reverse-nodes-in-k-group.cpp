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
    ListNode *findK(ListNode *temp, int k){
        ListNode *ptr= temp;
        int i =1;
        while(i<k && ptr!=NULL){
            ptr=ptr->next;
            i++;
        }
        return ptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
     ListNode *temp = head;
     ListNode *nextNode = NULL;
     ListNode *prevNode = NULL;
        while(temp!=NULL){
            ListNode *kNode = findK(temp, k);
            if(kNode==NULL){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if(temp==head){
                head = kNode;
            }
            else{
                prevNode->next =  kNode;
            }
            prevNode = temp;
            temp = nextNode; 
            
        }
        return head;
        

    }
};