/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node *ptr = head;
       Node *dummyNode = new Node(-1);
       Node *dummyTail = dummyNode;
       while(ptr!=NULL){
           Node * newNode = new Node(ptr->val);
           newNode->next = ptr->next;
           ptr->next = newNode;
           ptr= ptr->next->next;
           
       }
        ptr = head;
        while(ptr!=NULL){
            if(ptr->random!=NULL){
                 ptr->next->random = ptr->random->next;
            }
            else{
                ptr->next->random = NULL;
            }
           
            ptr= ptr->next->next;
        }
        ptr = head;
        while(ptr!=NULL){
            dummyTail->next = ptr->next;
            ptr->next= ptr->next->next;
            dummyTail = dummyTail->next;
            ptr= ptr->next;
            
        }
return dummyNode->next;





    }
};