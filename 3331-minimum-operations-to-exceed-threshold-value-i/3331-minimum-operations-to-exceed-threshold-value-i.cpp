class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end());

        int count = 0;
        while(pq.top() < k){
            if(pq.top() < k){
                pq.pop();
                count++;
            }
        }

        return count;
    }
};