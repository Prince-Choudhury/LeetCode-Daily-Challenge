/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool cyclePresent(ListNode* head, ListNode* &slow, ListNode* &fast){
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }

        if(head ->next == head){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        bool isTrue = cyclePresent(head, slow, fast);
       
        if(isTrue){
            slow = head;
            while(fast!=slow){
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
        }
        
        return NULL;
    }
};