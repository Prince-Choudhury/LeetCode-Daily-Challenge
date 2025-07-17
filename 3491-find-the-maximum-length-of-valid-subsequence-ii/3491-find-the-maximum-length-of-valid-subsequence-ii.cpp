class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
       for(auto &it:nums){
           it=it%k;
       }
        int n=nums.size();
        vector<vector<int>> dp(1e3+1,vector<int>(k+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                dp[nums[i]][j]=max(dp[nums[i]][j],1+dp[(j-nums[i]+k)%k][j]);
                ans=max(ans,dp[nums[i]][j]);        
            }
        }
        return ans;
        
    }
};