class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;  
        
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);

        int maxSoFar = nums[0];
        for (int i = 1; i < n; i++) {
            max_left[i] = maxSoFar;
            maxSoFar = max(maxSoFar, nums[i]);
        }

        maxSoFar = nums[n-1];
        for (int k = n - 2; k >= 0; k--) {
            max_right[k] = maxSoFar;
            maxSoFar = max(maxSoFar, nums[k]);
        }

        long long maxValue = 0;
        
        for (int j = 1; j < n - 1; j++) {
            long long left = (long long)max_left[j] - nums[j];  
            long long right = max_right[j];  
            maxValue = max(maxValue, left * right);
        }

        return maxValue;
    }
};