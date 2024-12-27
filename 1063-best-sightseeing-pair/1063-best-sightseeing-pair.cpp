class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!mp.empty()) {
                auto it = mp.rbegin();
                ans = max(ans, it->first + A[i] - i);
            }
            mp[A[i] + i]++; 
        }

        return ans;
    }
};