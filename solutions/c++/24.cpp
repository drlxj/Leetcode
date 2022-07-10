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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;                  // Node 1
            ListNode* tmp1 = cur->next->next->next;     // Node 3
            
            cur->next = tmp->next;            
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            
            cur = cur->next->next;
            
        }
        return dummyHead->next;
    } 
};