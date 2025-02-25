class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0, evncnt = 1, oddcnt = 0, MOD = 1e9+7;
        vector<int> prefixsum(n, 0);
        prefixsum[0] = nums[0];

        // Compute prefix sum array
        for (int i = 1; i < n; i++)
            prefixsum[i] = nums[i] + prefixsum[i - 1];

        for (int i = 0; i < n; i++) {
            if (prefixsum[i] % 2) {  
                ans = (ans + evncnt) % MOD;
                oddcnt++;
            } else {  
                ans = (ans + oddcnt) % MOD;
                evncnt++;
            }
        }
        return ans;
    }
};