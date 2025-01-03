class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        long long prefixSum = 0;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            if (prefixSum >= totalSum - prefixSum) {
                count++;
            }
        }
        
        return count;
    }
};
