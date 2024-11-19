class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store the frequency of elements
        long long maxSum = 0, currentSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); ++end) {
            // Add the current element to the window
            currentSum += nums[end];
            freq[nums[end]]++;

            // Shrink the window if its size exceeds k
            while ((end - start + 1) > k) {
                currentSum -= nums[start];
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);
                }
                start++;
            }

            // Check if the current window is valid and has size k
            if ((end - start + 1) == k && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};