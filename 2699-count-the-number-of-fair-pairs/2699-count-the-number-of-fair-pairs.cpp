class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();

            count += (right - left);
        }

        return count;
    }
};