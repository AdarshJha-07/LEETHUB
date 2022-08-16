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
        if(head==NULL)return NULL;
        Node * newHead = new Node(head->val);
        
        Node * temp = head ,* temp2 = newHead;
        unordered_map<Node*,Node*>ump;
        ump[head] = newHead;
        while(temp->next!=NULL){
             
            temp2->next = new Node( temp->next->val );
            ump[temp->next]  = temp2->next ;
            temp2 = temp2->next;
            temp = temp->next;
        }
       temp2 = newHead;
        temp =head;
        while(temp!=NULL){
       
            if(ump.find(temp->random)!=ump.end())
         temp2->random = ump[temp->random];  
         else temp2->random = NULL;   
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return newHead;
    }
};