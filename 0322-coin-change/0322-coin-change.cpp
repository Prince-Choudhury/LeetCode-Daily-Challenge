class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>&dp) {
        //base case
        if(amount == 0 ) {
            return 0;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }

        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++) {
 
            if(amount>=coins[i]) {
                int recAns = solve(coins, amount - coins[i], dp);
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }    
            }
            
        }

        dp[amount] = mini;
        return mini;
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, -1);
       int ans = solve(coins, amount, dp);

       if(ans == INT_MAX)
        return -1;
        else
        return ans;
    }
};