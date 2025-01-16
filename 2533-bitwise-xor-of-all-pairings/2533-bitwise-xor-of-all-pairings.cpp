class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size();
        int L2 = nums2.size();
        if (L1 % 2 == 0 && L2 % 2 == 0) {
            return 0;
        }
        int ONE = 0;
        int TWO = 0;
        for (int i = 0; i < max(L1, L2); i++) {
            if (i < L1) {
                ONE ^= nums1[i];
            }
            if (i < L2) {
                TWO ^= nums2[i];
            }
        }
        if (L1 % 2 == 0 && L2 % 2 != 0) {
            return ONE;
        }
        if (L1 % 2 != 0 && L2 % 2 == 0) {
            return TWO;
        }
        if (L1 % 2 == 0 && L2 % 2 == 0) {
            return 0;
        }
        return ONE ^ TWO;
    }
};