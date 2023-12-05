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
        if (!head) {
            return nullptr;
        }

        // First pass: Create new nodes and insert them after the original nodes
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Second pass: Copy random pointers
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Third pass: Separate the original and copied lists
        current = head;
        Node* newHead = head->next;
        Node* newCurrent = newHead;
        while (current) {
            current->next = current->next->next;
            current = current->next;

            if (newCurrent->next) {
                newCurrent->next = newCurrent->next->next;
                newCurrent = newCurrent->next;
            }
        }

        return newHead;
    }
};
