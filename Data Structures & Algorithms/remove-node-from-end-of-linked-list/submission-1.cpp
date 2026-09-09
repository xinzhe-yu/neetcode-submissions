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
        ListNode dummyn(0);
        ListNode* dummy = &dummyn;

        dummy->next = head; 
        
        ListNode* L = dummy; 
        ListNode* R = head;

        while (n > 0) {
            R = R->next; 
            n--;
        }

        while (R != nullptr) {
            L = L->next;
            R = R->next;
        }

        L->next = L->next->next; 
        return dummy->next;

    }
};
