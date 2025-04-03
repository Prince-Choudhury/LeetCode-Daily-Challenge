#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        int ans = solve(coins,amount,dp);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
    int solve(vector<int>& coins, int sum,vector<int> &dp) {
        if(sum ==0)
        {
            return 0;
        }
        if(sum < 0)
        {
            return INT_MAX-1;
        }
        int mini = INT_MAX;
        if(dp[sum]!= INT_MAX)
        {
            return dp[sum];
        }
        for(int i=0;i<coins.size();i++)
        {
            
            int recAns = solve(coins,sum-coins[i],dp);
            if(recAns != INT_MAX-1)
            {
                recAns +=1;
            }
            mini = min(recAns, mini);
 
        }
        dp[sum] = mini;
        return mini;
    }

};