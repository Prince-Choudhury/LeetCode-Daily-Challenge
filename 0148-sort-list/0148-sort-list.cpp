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

    ListNode* solve(ListNode* head, priority_queue<int, vector<int>, greater<int>>&pq){
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;

        ListNode* temp = head;

        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            node->next = newNode;
            node = newNode;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            return head;
        }

        priority_queue<int, vector<int>, greater<int>>pq;

        ListNode* temp = head;

        while(temp){
            pq.push(temp->val);
            temp = temp->next;
        }

        return solve(head, pq);
    }
};