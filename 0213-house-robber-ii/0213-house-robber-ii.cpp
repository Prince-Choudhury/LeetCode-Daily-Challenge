class Solution {
public:
    int solve(vector<int>arr, int index, vector<int>&dp){
    
        dp[index] = arr[index];

        for(int i = index-1; i>=0; i--){
            int temp = 0;

            if(i+2<arr.size()){
                temp = dp[i+2];
            }

            int include = arr[i] + temp;

            int exclude = 0 + dp[i+1];

            dp[i] = max(include, exclude);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int>arr1, arr2;

        for(int i = 0; i<n-1; i++){
            arr1.push_back(nums[i]);
        }

        for(int i = 1; i<n; i++){
            arr2.push_back(nums[i]);
        }

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);

        int ans1 = solve(arr1, arr1.size() - 1, dp1);
        int ans2 = solve(arr2, arr2.size() - 1, dp2);

        return max(ans1, ans2);
    }
};