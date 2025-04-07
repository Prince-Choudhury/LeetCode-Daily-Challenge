class Solution {
public:
    int solve(vector<int>arr, int index, vector<int>&dp){
        if(index>=arr.size()){
            return 0;
        }

        if(dp[index]!=-1){
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

        int ans1 = solve(arr1, 0, dp1);
        int ans2 = solve(arr2, 0, dp2);

        return max(ans1, ans2);
    }
};