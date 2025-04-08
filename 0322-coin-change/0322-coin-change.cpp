class Solution {
public:
    int solve(vector<int>arr, int amount, vector<int>&dp){
        if(amount == 0){
            return 0;
        }

        if(amount<0){
            return INT_MAX;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX;

        for(int i = 0; i<arr.size(); i++){
            int recAns = solve(arr, amount - arr[i], dp);

            if(recAns != INT_MAX){
                int ans = 1 + recAns;

                mini = min(mini, ans);
            }
        }

        dp[amount] = mini;

        return mini;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, -1);
        
        int ans = solve(coins, amount, dp);

        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};