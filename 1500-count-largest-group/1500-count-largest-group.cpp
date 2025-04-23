class Solution {
public:
    int sumOfDigits(int n) {
        int res = 0;
        while (n > 0) {
            int k = n % 10;
            n /= 10;
            res += k;
        }
        return res;
    }
    int countLargestGroup(int n) {
        vector<int> count(37, 0);
        int mx = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, ++count[sumOfDigits(i)]);
        }
        for (auto& it : count) {
            if (it == mx) {
                res++;
            }
        }
        return res;
    }
};