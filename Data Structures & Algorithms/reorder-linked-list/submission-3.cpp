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
    void reorderList(ListNode* head) {
        //mind the middle 
        ListNode* slow = head; 
        ListNode* fast = head; 
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow->next is head of second half 
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; 

        while (curr != nullptr) {
            ListNode* tmp = curr->next; 
            curr->next = prev;
            prev = curr; 
            curr = tmp; 
        }

        curr = head; 
        while (curr && prev) {
            ListNode* tmp1 = curr->next;
            ListNode* tmp2 = prev->next; 

            curr->next = prev; 
            prev->next = tmp1;  

            curr = tmp1;
            prev = tmp2; 
        }
    }
};
