class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
            maxi = max(maxi, sum);
            if(sum<0){
                sum = 0;
            }
        }

        int mini = INT_MAX;
        sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
            mini = min(mini, sum);
            if(sum>0){
                sum = 0;
            }
        }

        return max(maxi, abs(mini));
    }
};