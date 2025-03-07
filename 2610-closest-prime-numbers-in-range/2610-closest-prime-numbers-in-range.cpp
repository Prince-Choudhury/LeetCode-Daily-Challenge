#include <vector>
#include <climits> 

class Solution {
public:
    vector<bool> solve(int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) { // Start from i*i
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> mp = solve(right);
        int leftans = -1, rightans = -1;
        vector<int> ans;
        vector<int> v;

        for (int i = left; i <= right; i++) {
            if (mp[i]) { // No need for `== true`
                v.push_back(i);
            }
        }

        // Ensure we have at least two primes before finding the closest pair
        if (v.size() < 2) {
            ans.push_back(leftans);
            ans.push_back(rightans);
            return ans;
        }

        int dif = INT_MAX; // Fix: Set to INT_MAX instead of right - left
        for (int i = 0; i < v.size() - 1; i++) {
            int newdif = v[i + 1] - v[i];
            if (newdif < dif) {
                dif = newdif;
                leftans = v[i];
                rightans = v[i + 1];
            }
        }

        ans.push_back(leftans);
        ans.push_back(rightans);
        return ans;
    }
};