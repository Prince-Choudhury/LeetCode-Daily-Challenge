class Solution {
public:
    long long coloredCells(int n) {
        long long num1 = (n-1);
        long long num2 = n;
        return num1*num1 + num2*num2;
    }
};