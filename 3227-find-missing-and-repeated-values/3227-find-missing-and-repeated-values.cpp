class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();
        int a = 0, b = 0;
        long long sum = 0;
        long long x = n * n;
        long long actual_sum = x * (x + 1) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ele = grid[i][j];
                sum += ele;
                if (mp.find(ele) != mp.end()) {
                    a = ele;
                    mp[ele]++;
                } else {
                    mp[ele]++;
                }
            }
        }
        sum = sum - a;
        b = actual_sum - sum;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};