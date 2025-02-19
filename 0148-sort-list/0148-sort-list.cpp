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

*/



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
    void solve(priority_queue<int, vector<int>, greater<int>>& pq,
               ListNode* temp) {
        while (temp) {
            int d = temp->val;
            pq.push(d);
            temp = temp->next;
        }
    }
    void insert(ListNode*& a,
                priority_queue<int, vector<int>, greater<int>>& pq) {
        if (pq.empty())
            return; // Handle empty queue case

        // Initialize head if it's nullptr
        if (a == nullptr) {
            a = new ListNode(pq.top());
            pq.pop();
        }

        ListNode* current = a; // Maintain a pointer to traverse the list

        while (!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            current->next = new ListNode(ele);
            current = current->next;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* temp = head;
        solve(pq, temp);

        ListNode* NewHead = new ListNode(-1);
        insert(NewHead, pq);
        NewHead = NewHead->next;

        return NewHead;
    }
};