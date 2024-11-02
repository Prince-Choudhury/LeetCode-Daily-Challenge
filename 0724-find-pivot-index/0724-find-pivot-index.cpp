/*
// Method 1 : BruteForce Approach
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n;i++){
            int leftSum = 0;
            int rightSum = 0;
            
            //left Sum
            for(int j = 0; j<i; j++){
                leftSum = leftSum + nums[j];
            }

            //right Sum
            for(int j = i+1; j<n; j++){
                rightSum += nums[j];
            }

            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};

*/


/*

//Method 2
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftSum(n, 0);
        vector<int>rightSum(n, 0);

        //left Sum
        for(int i = 1; i<n; i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }

        //right Sum
        for(int i = n - 2; i>=0; i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }

        for(int i = 0; i<n; i++){
            if(leftSum[i] == rightSum[i]){
                return i;
            }
        }

        return -1;
    }
};



// Method 3
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Calculate the total sum of all elements in the array
        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            // If the left sum is equal to the total sum minus the left sum and the current element,
            // then this is the pivot index.
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};
*/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int lsum = 0;
        int rsum = 0;
        int mini = -1;

        for(int i = 1; i<n; i++){
            rsum += nums[i];
        }

        for(int i = 0; i<n; i++){
            if(lsum == rsum){
                return i;
            }

            if(lsum!=rsum){
                lsum += nums[i];
                if(i+1<n)
                    rsum = rsum - nums[i+1];
            }
        }

        return -1;

    }

};