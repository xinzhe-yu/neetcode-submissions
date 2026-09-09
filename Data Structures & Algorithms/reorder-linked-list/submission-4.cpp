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

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondList = slow->next;
        slow->next = nullptr; 

        // reverse the list at secondList
        ListNode* prev = nullptr;
        ListNode* curr = secondList; 
        while(curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp; 
        }
        ListNode* secondHead = prev; 

        while(secondHead != nullptr) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = secondHead->next; 
            head->next = secondHead;
            secondHead->next = tmp1;
            head = tmp1;
            secondHead = tmp2; 
        }
    }
};
