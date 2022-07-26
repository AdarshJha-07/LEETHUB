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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        
        priority_queue<pair<int,ListNode*> ,vector<pair<int,ListNode*>> ,greater<pair<int,ListNode*>> >pq;
          
        for( int i = 0; i<list.size(); i++)
        {  if(list[i])
            pq.push({list[i] -> val , list[i]});
        }
        if(pq.empty()) return NULL;
        ListNode * ans = new ListNode(0);
        ListNode * head = ans;
        while( !pq.empty()){
            
            auto u = pq.top();
            
            ans -> next = u.second;
            ans = ans -> next;
            pq.pop();
            
            if( u.second -> next != NULL){
                pq.push({u.second -> next -> val ,u.second -> next});
            }
            
        }
  return head -> next;  
    }
};