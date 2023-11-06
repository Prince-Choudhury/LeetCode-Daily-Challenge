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
        if (head->next == NULL) {
            return NULL;
        }
        
        ListNode* left = head;
        ListNode* right = head;
        
        while (n > 0) {
            right = right->next;
            n--;
        }
        
        if (right == NULL) {
            return head->next;
        }
        
        while (right->next != NULL) {
            left = left->next;
            right = right->next;
        }
        
        left->next = left->next->next;
        return head;
    }
};