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
    ListNode* deleteMiddle(ListNode* head) {
     
     if(!head||!head->next)return NULL;
       ListNode *temp1=NULL,*temp2=head;
        int count=0;
        while(temp2&&temp2->next){
            temp1=(temp1==NULL)?head:temp1->next;
            
            temp2=temp2->next->next;
        }
      
      temp1->next = temp1->next->next;
      //  cout<<temp1->val<<endl;
        return head;
    }
};