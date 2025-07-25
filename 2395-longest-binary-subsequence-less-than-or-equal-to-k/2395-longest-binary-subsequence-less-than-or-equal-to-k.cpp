class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0;
        long long cur = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if(c == '0') {
                res++;
            } else if(res < 31 && cur + (1LL << res) <= k) {
                cur += 1LL << res;
                res++;
            }
        }
        return res;
    }
};