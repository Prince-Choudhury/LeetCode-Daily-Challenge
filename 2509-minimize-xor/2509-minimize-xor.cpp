class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            if(num2 & (1 << i)) // set bit
                count++;
        }

        int res = 0;
        for(int i = 31; count && i >= 0; i--) {
            if(num1 & (1 << i)) { // set bit
                res |= (1 << i);
                count--;
            }
        }

        for(int i = 0; count && i < 31; i++) {
            if(!(num1 & (1 << i))) { // not-set bit
                res |= (1 << i);
                count--;
            }
        }

        return res;
    }
};