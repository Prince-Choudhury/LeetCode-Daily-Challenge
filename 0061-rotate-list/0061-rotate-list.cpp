class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        ListNode* temp = head;
        int len = 1;
        while(temp->next){
            len++;
            temp = temp->next;
        }

        k = k % len;
        if(k == 0){
            return head;
        }

        temp->next = head;

        int count = len - k;

        ListNode* ptr = head;

        while(count!=1){
            count--;
            ptr = ptr->next;
        }

        ListNode* newHead = ptr->next;
        ptr->next = NULL;

        return newHead;
    }
};