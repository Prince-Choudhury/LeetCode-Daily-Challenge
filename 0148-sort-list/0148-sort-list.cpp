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
    ListNode* solve(vector<int>&arr){
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        for(int i = 0; i<arr.size(); i++){
            ListNode* temp1 = new ListNode(arr[i]);
            temp->next = temp1;
            temp = temp1;
        }

        return head->next;

    }
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        return solve(arr);

    }
};