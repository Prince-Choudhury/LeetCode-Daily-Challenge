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
    ListNode* solve(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* head1 = new ListNode(head->val);
        ListNode* tempo = head1;

        ListNode* temp = head->next;

        while(temp){
            ListNode* newNode = new ListNode(temp->val);
            tempo->next = newNode;
            tempo = newNode;
            temp = temp->next;
        }

        head1 = solve(head1);

        ListNode* temp1 = head;
        ListNode* temp2 = head1;

        while(temp1){
            if(temp1->val != temp2->val){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};