class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return 0;
        int K=sum/2;
        bitset<10001> dp;
        dp[K]=1;
        for (int x: nums) {
            for (int j=0; j+x<=K; j++) {
                dp[j]=dp[j]|dp[j+x];
            }
        }
        return dp[0];
    }
};
