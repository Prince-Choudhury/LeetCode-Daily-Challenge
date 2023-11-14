lass Solution {
public:

    ListNode* reverseUsingRecursion(ListNode* &prev, ListNode* &curr){
        //base case
        if(curr==NULL){
            return prev;
        }

        //ek case solve karo
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //Recursion sambhal lega
        return reverseUsingRecursion(prev, curr);

    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseUsingRecursion(prev, curr);
        //while(curr != NULL){
            //ListNode* nextNode = curr->next;
            //curr->next = prev;
            //prev = curr;
            //curr = nextNode;
        //}
        //return prev;
        
    }
};