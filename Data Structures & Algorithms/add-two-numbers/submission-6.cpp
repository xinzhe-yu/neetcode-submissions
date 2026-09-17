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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; 

        ListNode dummyn;
        ListNode* dummy = &dummyn;

        while (l1 || l2) {
            
            int v1 = (l1) ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;


            int sum = v1 + v2 + carry;
            carry = 0;
            if (sum >= 10) {
                carry = sum / 10;
                sum -= carry * 10;
                
            }

            ListNode* newNode = new ListNode(sum);
            dummy->next = newNode; 
            dummy = dummy->next; 

            if (l1) l1 = l1->next;
            
            if (l2) l2 = l2->next;

        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            dummy->next = newNode;
        }

        return dummyn.next;
        
    }
};
