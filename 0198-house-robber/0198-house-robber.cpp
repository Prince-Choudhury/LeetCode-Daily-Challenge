class Solution {
public:

    /*
    //1. Using Recursion
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



    /*

    //Uisng Recursion + Memo.
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

    }*/


    //Using Tabulationg

    int solve(vector<int>arr, vector<int>&dp, int n){
        dp[n-1] = arr[n-1];

        for(int index = n-2; index>=0; index--){
            int temp = 0;

            //Include
            if(index+2<n){
                temp = dp[index+2];
            }
            int incAns = arr[index] + temp;
            

            //Exclude
            int excAns = 0 + dp[index+1];

            dp[index] = max(incAns, excAns);

        }

        return dp[0];
    }



    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        return solve(nums, dp, n);
    }
};