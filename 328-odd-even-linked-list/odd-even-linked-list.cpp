class Solution {
public:
    void insertAtTail(ListNode* &tail, ListNode* ptr){
        tail->next = ptr;
        tail = ptr;
    }
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead = new ListNode (-1);
        ListNode *evenTail = evenHead;
        ListNode *oddHead = new ListNode (-1);
        ListNode *oddTail = oddHead;
        ListNode *ptr = head;
        int i=1;
        while(ptr!=NULL){
            if(i%2 ==0){
                 insertAtTail(evenTail, ptr);
            }
            else{
                insertAtTail(oddTail, ptr);
            }
            ptr=ptr->next;
            i++;
        }
        oddTail->next = evenHead->next;
        evenTail->next = NULL;
            delete(evenHead);
            return oddHead->next;
        
        
    }
};
