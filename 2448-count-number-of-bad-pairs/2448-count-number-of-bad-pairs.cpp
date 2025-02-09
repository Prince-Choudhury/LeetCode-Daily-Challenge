class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long goodPairs = 0;
        long long totalPairs = (n*(n-1))/2; //nc2

        unordered_map<int, long long> mp;

        for(int i = 0; i<n; i++){
            int key = nums[i] - i;
            goodPairs+= mp[key];
            mp[key]++;
        }

        return totalPairs - goodPairs;

    }
};