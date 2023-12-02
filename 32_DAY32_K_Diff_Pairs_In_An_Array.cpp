class Solution {
public:
int findPairs(vector<int>& nums, int k) {
    if (k < 0) {
        return 0;
    }

    unordered_map<int, int> num_count;
    int pair_count = 0;

    for (int num : nums) {
        if (num_count.find(num) != num_count.end()) {
            if (k == 0 && num_count[num] == 1) {
                pair_count += 1;
            }
            num_count[num] += 1;
        } else {
            if (num_count.find(num + k) != num_count.end()) {
                pair_count += 1;
            }
            if (num_count.find(num - k) != num_count.end()) {
                pair_count += 1;
            }
            num_count[num] = 1;
        }
    }

    return pair_count;
}


};