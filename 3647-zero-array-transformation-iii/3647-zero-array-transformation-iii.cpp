class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), qsz = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int>pq;
        vector<int>sweep(n + 1, 0);
        int ind = 0, cs = 0;
        for (int i = 0; i < n; i++) {
            cs += sweep[i];
            while (ind < qsz && queries[ind][0] <= i) {
                pq.push(queries[ind][1]);
                ind++;
            }
            while (cs < nums[i] && !pq.empty() && pq.top() >= i) {
                cs++;
                sweep[pq.top() + 1]--;
                pq.pop();
            }
            if (cs < nums[i])
                return -1;
        }
        return pq.size();
    }
};