class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int sum = nums[i];
            for(int j = i+1; j<n; j++){
                if(nums[j-1]<nums[j]){
                    sum+=nums[j];
                }
                else{
                    break;
                }
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};