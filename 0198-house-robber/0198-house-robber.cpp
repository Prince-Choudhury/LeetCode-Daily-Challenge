class Solution {
public:

    /*
    int solve(vector<int>arr, int n){
        if(n<0){
            return 0;
        }

        //Include
        int incAns = arr[n] + solve(arr, n-2);

        //Exclude
        int excAns = 0 + solve(arr, n-1);

        return max(incAns, excAns);
    }*/

    int solveUsingMem(vector<int> arr, vector<int>&dp, int index){
        if(index>=arr.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        //Include
        int incAns = arr[index] + solveUsingMem(arr, dp, index+2);

        //Exclude
        int excAns = 0 + solveUsingMem(arr, dp, index+1);

        dp[index] = max(incAns, excAns);

        return dp[index];

    }

    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size() + 1, -1);

        return solveUsingMem(nums, dp, 0);
    }
};