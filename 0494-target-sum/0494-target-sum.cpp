class Solution {
public:
    int target;
    int knapsack(vector<int>& nums, int n, int curSum) {
        if(n == 0) {
            if(curSum == target) 
                return 1;
            return 0;
        }
        return knapsack(nums, n - 1, curSum + nums[n - 1]) + knapsack(nums, n - 1, curSum - nums[n - 1]);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int sum) {
        target = sum;
        return knapsack(nums, nums.size(), 0);
    }
};