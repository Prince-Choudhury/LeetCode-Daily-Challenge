/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>ans(n);

        for(int index = 0; index<n; index++){
            int newIndex = (index + k)%n;
            ans[newIndex] = nums[index];
        }

        nums = ans;
    }
};
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // In case k is larger than the array size
        vector<int> temp(k);  

        for(int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        for(int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};