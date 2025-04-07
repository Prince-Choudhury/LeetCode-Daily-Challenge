class Solution {
public:
    int solve(vector<int>arr, int index, vector<int>&dp){
        if(index>=arr.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int include = arr[index] + solve(arr, index+2, dp);
        
        int exclude = 0 + solve(arr, index + 1, dp);
        
        int ans = max(include, exclude);

        dp[index] = ans;

        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(nums, 0, dp);
    }
};