class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            // Find the first valid index j where nums[i] + nums[j] >= lower
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            
            // Find the first invalid index j where nums[i] + nums[j] > upper
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();

            // Add the count of valid pairs between left and right
            count += (right - left);
        }

        return count;
    }
};