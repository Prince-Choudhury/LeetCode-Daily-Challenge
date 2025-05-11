class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false; 
        int count = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            if (*it % 2 != 0) {
                count++;
                if (count == 3) {
                    return true;  
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
};
