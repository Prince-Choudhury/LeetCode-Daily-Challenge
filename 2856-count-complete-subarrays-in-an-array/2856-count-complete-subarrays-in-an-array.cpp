class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp, all;
        for (auto n : nums)
            all[n]++;
        int front = 0, back = 0, ans = 0;
        while (front < nums.size()) {
            mp[nums[front]]++;
            while (back <= front && mp.size() == all.size()) {
                if (--mp[nums[back]] == 0)
                    mp.erase(nums[back]);
                back++;
                ans += (nums.size() - front);
            }
            front++;
        }
        return ans;
    }
};