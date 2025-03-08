class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOperations = k;  

   
        for (int i = 0; i <= blocks.size() - k; i++) {
            int whiteCount = 0;


            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') {
                    whiteCount++;
                }
            }

      
            minOperations = min(minOperations, whiteCount);

            if (minOperations == 0) {
                break;
            }
        }

        return minOperations;
    }
};