class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long countZero1 = 0;
        long long countZero2 = 0;
        for(auto it : nums1){
            sum1+=it;
            if(it == 0){
                countZero1++;
            }
        }
        for(auto it : nums2){
            sum2+=it;
            if(it == 0){
                countZero2++;
            }
        }
        if((countZero1==0 && sum1 < sum2+countZero2)||(countZero2==0 && sum2 < sum1+countZero1)){
            return -1;
        }
        return max(countZero1+sum1, countZero2+sum2);
    }
};