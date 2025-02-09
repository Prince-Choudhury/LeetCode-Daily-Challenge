

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; // Total pairs (nC2)

        std::unordered_map<int, long long> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key]; 
            freq[key]++; 
        }

        return totalPairs - goodPairs; 
    }
};