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
    bool hasCycle(ListNode* head) {
        ListNode* slow;
        ListNode* fast;
        if (head) {
            slow = head; 
        } else {
            return false;
        }
        if (head->next) {
            fast = head->next; 
        } else {
            return false; 
        }

        for (;fast != nullptr && fast->next != nullptr; slow = slow->next, fast = fast->next->next) {
            if (fast == slow) {
                return true; 
            }
        }

        return false;
    }
};
