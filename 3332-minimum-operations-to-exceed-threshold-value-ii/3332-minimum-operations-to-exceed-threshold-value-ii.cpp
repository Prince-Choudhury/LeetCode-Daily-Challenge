class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        int count = 0;
        while(pq.top()<k){
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();

            long long ele = min(top1, top2)*2 + max(top1, top2);
            pq.push(ele);
            count++;
        }

        return count;
    }
};