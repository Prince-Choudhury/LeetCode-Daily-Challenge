class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                // Calculate the sum of the next k elements
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n]; 
                }
            } else {
                // Calculate the sum of the previous k elements
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n]; 
                }
            }

         
            ans[i] = sum;
        }

        return ans;
    }
};