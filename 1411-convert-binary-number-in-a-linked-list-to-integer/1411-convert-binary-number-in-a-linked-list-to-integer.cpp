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
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(),v.end());

        int num =0;
        for(int i=0;i<v.size();i++){
            num += ( v[i] * (1<<i) );
        }
        return num;
    }
};