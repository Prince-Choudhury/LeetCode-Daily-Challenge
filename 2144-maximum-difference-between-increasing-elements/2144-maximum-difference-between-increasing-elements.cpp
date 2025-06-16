class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int ans = 0, maxValue = 0, n = nums.size();   

        vector<int> maxArr(n);
        for(int i = n - 1; i >= 0; i--)
        {
            maxArr[i] = maxValue;
            maxValue = max(maxValue, nums[i]);
        }

        for(int i = 0; i < n; i++)
            ans = max(ans, maxArr[i] - nums[i]);
        return ans ? ans : -1; 
    }
};