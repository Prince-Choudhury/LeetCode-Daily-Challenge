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

/*
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
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

    ListNode* solve(ListNode* head, int k){
        ListNode* temp = head;

        while(k!=1){
            k--;
            temp = temp->next;
        }

        ListNode* head2 = temp->next;
        temp->next = NULL;

        head = reverseLL(head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0 || k == 1){
            return head;
        }

        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }

        int count = len/k;

        temp = head;

        while(count!=1){
            count--;
            int i = k;
            while(i!=1){
                i--;
                temp = temp->next;
            }

            ListNode* head2 = temp->next;
            temp->next = NULL;

            head = reverseLL(head);

        }
    }
};

*/

class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0 || k == 1){
            return head;
        }

        vector<int>arr;
        ListNode* temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();

        for(int i = 0; i + k <= n; i += k){
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        ListNode* dummy = new ListNode(-1);

        temp = dummy;

        for(int i = 0; i<arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
};