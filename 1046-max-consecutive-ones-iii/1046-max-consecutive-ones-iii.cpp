
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int maxLen = 0;
        int zeroes = 0;
        int l = 0;
        for(int r = 0; r<arr.size(); r++){
            if(arr[r] == 0){
                zeroes++;
            }

            while(zeroes>k){
                if(arr[l] == 0){
                    zeroes--;
                }
                l++;
            }

            if(zeroes<=k){
                maxLen = max(maxLen, r-l+1);
            }
            
        }

        return maxLen;
    }
};