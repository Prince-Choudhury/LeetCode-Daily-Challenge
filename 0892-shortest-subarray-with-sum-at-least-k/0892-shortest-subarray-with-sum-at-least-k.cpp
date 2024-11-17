/*

// All test cases are not passing using these approaches
	•	Stick to the sliding window approach only for non-negative arrays.
	•	For arrays with both positive and negative numbers, use prefix sums + deque for a general solution.
    
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minlen = INT_MAX;
        
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum = sum + nums[j];

                if(sum>=k){
                    minlen = min(minlen, j-i+1);
                }
            }
        }

        if(minlen == INT_MAX){
            return -1;
        }

        return minlen;
    }
};


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minlen = INT_MAX;

        int l = 0, sum = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            // Shrink the window until the sum is less than k
            while (sum >= k) {
                minlen = min(minlen, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return (minlen == INT_MAX) ? -1 : minlen;
    }
};
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;  // Store indices of prefix sums
        int minlen = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Check if there's a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minlen = min(minlen, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (minlen == INT_MAX) ? -1 : minlen;
    }
};