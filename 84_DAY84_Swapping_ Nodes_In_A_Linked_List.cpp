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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* kthFromBegin = NULL;
        ListNode* kthFromEnd = NULL;

        // Move fast pointer to the kth node from the beginning
        for (int i = 1; i < k; ++i) {
            if (fast) {
                kthFromBegin = fast;
                fast = fast->next;
            }
        }

        // If k is greater than the length of the linked list
        if (!fast) {
            return NULL;
        }

        // Save the kth node from beginning
        kthFromBegin = fast;

        // Move fast pointer to the end of the linked list
        while (fast) {
            kthFromEnd = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // Swap values of kth from beginning and kth from end
        if (kthFromBegin && kthFromEnd) {
            swap(kthFromBegin->val, kthFromEnd->val);
        }

        return head;
    }
};
