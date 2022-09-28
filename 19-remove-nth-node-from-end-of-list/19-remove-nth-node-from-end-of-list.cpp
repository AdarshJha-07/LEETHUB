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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)  return NULL;
        ListNode* temp1 = new ListNode(-1);
        temp1 -> next = head;
    
        ListNode * temp2 = head;
        int k = n;
        while(k--){
            temp2= temp2 -> next;
        }
        
        ListNode* temp3 = temp1;
        // cout<<temp2->val<<endl;
        while(temp2){
            temp2 = temp2 -> next;
            temp3 = temp3 -> next;
        }
        cout<<temp3->val<<endl;
        temp3->next = temp3->next->next;
        return temp1->next;
    }
};