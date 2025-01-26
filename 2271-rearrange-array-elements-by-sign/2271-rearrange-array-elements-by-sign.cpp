class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        vector<int>ans(n);

        for(int index = 0; index<n; index++){
            if(nums[index] >= 0){
                ans[i] = nums[index];
                i = i+2;
            }
            else{
                ans[j] = nums[index];
                j = j+2;
            }
        }

        return ans;
    }
};