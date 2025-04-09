class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> M;
        for (int a : nums) {
            if (a < k) {
                return -1;
            }
            M[a]++;
            if(a != k && M[a] == 1){
                ans++;
            }
        }
        return ans;
    }
};