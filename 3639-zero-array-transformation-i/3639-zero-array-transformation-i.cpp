class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        vector<int> freq(n + 1, 0);         
        
        for (auto& q : queries) {
            freq[q[0]]++;
            freq[q[1] + 1]--;
        }
        
        int op = 0;
        for (int i = 0; i < n; i++) {
            op += freq[i];
            if (op < nums[i]) return false;
        }
        return true;        
    }
};