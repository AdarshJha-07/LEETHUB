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
      Node * temp = head,*prev = NULL;
        if(head==NULL)return NULL;
        while(temp)
        {
          prev =  temp->next;
          temp->next = new Node(temp->val);
           temp->next->next = prev;
            temp = prev;
              
        }
       
        temp = head;
        Node* temp1 = temp->next;
        while(temp){
            
        if(temp->random!=NULL)    temp1->random = temp->random->next;
         else temp1->random = NULL;
          
            temp = temp->next->next;
         if(temp==NULL)
             break;
            
          temp1 = temp->next;
        }
     
        
        temp1 =head->next;
        temp = head;
        Node *newHead = temp1;
       
        while( temp){
            
           temp->next = temp->next->next;
            
          if(temp1->next!=NULL)  temp1->next = temp1->next->next;
           else temp1->next = NULL;
            
         
            temp = temp->next;
            temp1 = temp1->next;
        }
        return newHead;
    }
};