class Solution {
    public:
        int countDays(int days, vector<vector<int>> &nums) {
            int maxi = 0, temp = 1;
            sort(nums.begin() , nums.end());
            for (const auto &m: nums)
            {
                maxi += max(0, m[0] - temp);
                temp = max(temp, m[1] + 1);
                if (temp > days)
                    break;
            }
            return maxi + max(0, days - temp + 1);
        }
};