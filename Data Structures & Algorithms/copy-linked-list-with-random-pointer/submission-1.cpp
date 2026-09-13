/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        for (Node* curr = head; curr; curr = curr->next) {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode; 
        }

        for(Node* curr = head; curr; curr = curr->next) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
        }

        return mp[head];
    }
};
