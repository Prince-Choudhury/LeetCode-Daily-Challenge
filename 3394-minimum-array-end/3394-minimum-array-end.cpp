class Solution {
public:
    long long minEnd(int n, int x) {
        long long curr = x;
        while (--n)
        {
            curr = (curr + 1) | x;
        }
        
        return curr;
    }
};