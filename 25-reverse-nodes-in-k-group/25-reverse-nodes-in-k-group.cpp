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
    
    
    ListNode* reverse(ListNode *head){
        
        ListNode *curr,*next,*prev;
        curr = next = head;
        prev = NULL;
        
        while( next != NULL ){
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return head;
    }
    
    ListNode* solve(ListNode* head,int len,int k){
        
        if(len < k){
            return head;
        }      
        
        int K = k-1;
        
        ListNode* temp = head;
        
        while(K--){
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        
        temp->next = NULL;
        
        ListNode *reversedHead = reverse(head);
        
        ListNode *temp2 = reversedHead;
        
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = solve(newHead,len-k,k);
        
        return reversedHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        int len = 0;
        
        ListNode *temp = head;
        
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        return solve(head,len,k);
        
    }
};