class Solution {
public:
    bool findSubsequence(vector<int>& nums, int index, int sum, int k) {
        // If sum becomes k, return true
        if (sum == k) return true;

        // Base Case: If we reach the end, return false
        if (index == nums.size()) return false;

        // Include current element
        if (findSubsequence(nums, index + 1, sum + nums[index], k)) 
            return true;

        // Exclude current element
        if (findSubsequence(nums, index + 1, sum, k)) 
            return true;

        return false;
    }
    
    bool checkPowersOfThree(int n) {
        vector<int> arr;
        bool run =true;
        int mul = 1;
        while(run)
        {
            if(mul>n)
            {
                run = false;
            }else{
                arr.push_back(mul);
                mul = mul*3;
            }
        }
        bool count = findSubsequence(arr,0, 0, n);
        return count;
       
    }
};