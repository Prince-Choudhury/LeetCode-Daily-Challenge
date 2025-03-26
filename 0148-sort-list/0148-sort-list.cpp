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

    ListNode* solve(ListNode* head, vector<int>arr){
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;

        ListNode* temp = head;

        for(int i = 0; i<arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
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

        vector<int>arr;

        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        return solve(head, arr);
    }
};